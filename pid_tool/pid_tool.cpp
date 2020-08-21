#include "pid_tool.hpp"
#include <QTimer>

PidTool::PidTool(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    mChartLeft = new RunTimeChart(this);
    QHBoxLayout *chartLayout = new QHBoxLayout();
    chartLayout->addWidget(mChartLeft);
    layout->addLayout(chartLayout);

    mChartLeft->addChannal("当前车速", Qt::red);
    mChartLeft->addChannal("目标车速", Qt::green);
    mChartLeft->addChannal("当前油门", Qt::blue, Qt::AlignRight);
    mChartLeft->addChannal("请求油门", Qt::black, Qt::AlignRight);
    mChartLeft->addChannal("坡度值", Qt::yellow);
    mChartLeft->addChannal("发动机转速", Qt::gray);

    // 图表控制
    QHBoxLayout *btnLayout = new QHBoxLayout();
    layout->addLayout(btnLayout);
    btnLayout->setAlignment(Qt::AlignLeft);
    QPushButton *startBtn = new QPushButton("Start");
    btnLayout->addWidget(startBtn);
    startBtn->setCheckable(true);
    connect(startBtn, &QPushButton::clicked, this, &PidTool::start);


    // 数据保存
    mSaveBtn = new QPushButton("Save", this);
    btnLayout->addWidget(mSaveBtn);
    connect(mSaveBtn, &QPushButton::clicked, this, &PidTool::saveData);

    // 加载数据
    mLoadBtn = new QPushButton("Load", this);
    btnLayout->addWidget(mLoadBtn);
    connect(mLoadBtn, &QPushButton::clicked, this, &PidTool::loadData);

    // mEnableCtlBtn = new QPushButton("EnableCtl", this);
    // btnLayout->addWidget(mEnableCtlBtn);

    // 车辆控制
    // QHBoxLayout *throLayout = new QHBoxLayout();
    // layout->addLayout(throLayout);
    // QLabel *throLabel = new QLabel("Thro:", this);
    // throLayout->addWidget(throLabel);
    // mThroSlider = new QSlider(this);
    // mThroSlider->setOrientation(Qt::Horizontal);
    // mThroSlider->setRange(0, 100);
    // throLayout->addWidget(mThroSlider);
    // connect(mThroSlider, &QSlider::valueChanged, this, &PidTool::ctlThro);




    dataRecTimer = new QTimer(this);
    connect(dataRecTimer, &QTimer::timeout, this, &PidTool::updateData);
}

PidTool::~PidTool()
{
    for (auto itor = mDatas.begin(); itor != mDatas.end(); itor++)
    {
        (*itor)->clear();
        delete (*itor);
    }
    mDatas.clear();
}

void PidTool::start()
{
    QPushButton *btn = static_cast<QPushButton*>(sender());
    mChartLeft->setStart(btn->isChecked());

    // 如果正在刷新数据则不保存
    mSaveBtn->setEnabled(!btn->isChecked());
    mLoadBtn->setEnabled(!btn->isChecked());

    if(btn->isChecked())
    {
        for (auto itor = mDatas.begin(); itor != mDatas.end(); itor++)
        {
            (*itor)->clear();
            delete (*itor);
        }
        mDatas.clear();
        mStartTime = QDateTime::currentMSecsSinceEpoch();
        dataRecTimer->start(10);

    }
    else
    {
        dataRecTimer->stop();
    }
    
}

void PidTool::updateData()
{
    if(mDatas.empty())
    {
        DataBuffer *data = new DataBuffer;
        mDatas.push_back(data);
        mDatas.back()->reserve(MAX_DATA_SIZE);
    }
    auto itor = mDatas.back();
    // std::cout << "itor:" << itor << std::endl;
    if((itor)->size() == DataDefines::MAX_DATA_SIZE)
    {
    //     std::cout << "save data now: " << mDatas.size() << std::endl;
        if(mDatas.size() >= MAX_BUF_SIZE)
        {
            QMessageBox::warning(this, "Warning", "数据缓存已满，将丢失最早的数据！！！");
            mDatas.pop_front();
        }

        mDatas.push_back(new DataBuffer());
        itor = mDatas.back();
        (itor)->reserve(MAX_DATA_SIZE);
    }


    (itor)->push_back(DataBufferItem(QDateTime::currentMSecsSinceEpoch() - mStartTime, \
        RosHelper::getInstance().getRealSpeed(), RosHelper::getInstance().getSetSpeed(),\
        RosHelper::getInstance().getRealThro(), RosHelper::getInstance().getSetThro(),\
        RosHelper::getInstance().getSlope(), RosHelper::getInstance().getEngineSpeed()));


    mChartLeft->updateData(0, RosHelper::getInstance().getRealSpeed());
    mChartLeft->updateData(1, RosHelper::getInstance().getSetSpeed());
    mChartLeft->updateData(2, RosHelper::getInstance().getRealThro());
    mChartLeft->updateData(3, RosHelper::getInstance().getSetThro());
    mChartLeft->updateData(4, RosHelper::getInstance().getSlope());
    mChartLeft->updateData(5, RosHelper::getInstance().getEngineSpeed());
}

void PidTool::ctlThro(int thro)
{
    if(mEnableCtlBtn->isChecked()) {
    // RosHelper::getInstance().setThro((double)mThroSlider->value() / 100.0);
    }
}

void PidTool::saveData()
{
    QString saveFile = QFileDialog::getSaveFileName(this, "file to save...", "./", "*.csv");
    if(saveFile.isEmpty()) return;

    std::ofstream fout(saveFile.toStdString());

    if(fout.is_open())
    {
        fout << "timestamp(ms),RealSpeed(m/s),SetSpeed(m/s),RealThro,Brake,Slope,EngineSpeed" << std::endl;
        for(auto itor = mDatas.begin(); itor != mDatas.end(); itor++)
        {
            for(auto item = (*itor)->begin(); item != (*itor)->end(); item++)
            {
                fout << item->stamp << "," << item->realSpeed << "," << item->setSpeed << ","\
                << item->realThro << "," << item->realBrake << "," << item->slope << "," << item->engineSpeed << std::endl;
                
            }
        }
        fout.close();
    }
}

void PidTool::loadData()
{
    QString loadFile = QFileDialog::getOpenFileName(this, "file to load...", "./", "*.csv");
    if(loadFile.isEmpty()) return;

    mChartLeft->uploadFile(loadFile);
}


