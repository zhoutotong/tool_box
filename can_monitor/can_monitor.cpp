#include "can_monitor.hpp"

#include <QHeaderView>


CanMonitor::CanMonitor(QWidget *parent) : QWidget(parent)
  , mInfoTableWidget(nullptr)
  , mCanFrameLoadRateBar(nullptr)
{
    const QStringList header = {"MsgId", "00", "01", "02", "03", "04", "05", "06", "07"};

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft);

    // 帧数据显示
    mInfoTableWidget = new QTableWidget(this);
    layout->addWidget(mInfoTableWidget);

    mInfoTableWidget->setColumnCount(header.size());
    mInfoTableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
    mInfoTableWidget->setHorizontalHeaderLabels(header);
    mInfoTableWidget->setRowCount(5);

    // 总线负载率
    QHBoxLayout *frameLoadRateLayout = new QHBoxLayout();
    layout->addLayout(frameLoadRateLayout);
    frameLoadRateLayout->addWidget(new QLabel("负载率"));
    mCanFrameLoadRateBar = new QProgressBar(this);
    frameLoadRateLayout->addWidget(mCanFrameLoadRateBar);
    mCanFrameLoadRateBar->setRange(0, 100);
    mCanFrameLoadRateBar->setTextVisible(true);
    mCanFrameLoadRateBar->setValue(14);

    // 帧统计

    // 控制窗口
    QHBoxLayout *cfgLayout = new QHBoxLayout();
    cfgLayout->setAlignment(Qt::AlignLeft);
    
    layout->addLayout(cfgLayout, Qt::AlignLeft);
    QLabel *modelLabel = new QLabel("显示模式");
    modelLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    cfgLayout->addWidget(modelLabel, Qt::AlignLeft);

    QComboBox *modelSelectBox = new QComboBox();
    // connect(modelSelectBox, &QComboBox::currentIndexChanged, this, &CanMonitor::changeMonitorModel);
    connect(modelSelectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeMonitorModel(int)));
    cfgLayout->addWidget(modelSelectBox, Qt::AlignLeft);
    modelSelectBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    modelSelectBox->addItem("原始数据");
    modelSelectBox->addItem("统计数据");

}

CanMonitor::~CanMonitor()
{

}

void CanMonitor::changeMonitorModel(int index)
{
    if(index == 0)
    {
        __change2RawModel();
    }
    else if(index == 1)
    {
        __change2DetailModel();
    }
}

void CanMonitor::__change2RawModel()
{
    const QStringList header = {"MsgId", "00", "01", "02", "03", "04", "05", "06", "07"};
    mInfoTableWidget->setColumnCount(header.size());
    mInfoTableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
    mInfoTableWidget->setHorizontalHeaderLabels(header);

    // 设置表格宽度规则，自适应大小
    for(int i = 0; i < header.size(); i++)
    {
        mInfoTableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}
void CanMonitor::__change2DetailModel()
{
    const QStringList header = {"MsgId", "00", "01", "02", "03", "04", "05", "06", "07", "fram cnt"};
    mInfoTableWidget->setColumnCount(header.size());
    mInfoTableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
    mInfoTableWidget->setHorizontalHeaderLabels(header);

    // mInfoTableWidget->addActions()



    // 设置表格宽度规则，自适应大小
    for(int i = 0; i < header.size(); i++)
    {
        mInfoTableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}
