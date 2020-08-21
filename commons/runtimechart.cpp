#include "runtimechart.h"
#include <QDebug>

RunTimeChart::RunTimeChart(QWidget *parent) : QWidget(parent)
  , mXRange(50.0f)
  , mIsStart(false)
  , m_tooltip(nullptr)
  , mLoadFile(nullptr)
  , mLoadFilerTimer(nullptr)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QHBoxLayout *chartLayout = new QHBoxLayout();
    layout->addLayout(chartLayout);

    mChartView = new QtCharts::QChartView(this);
    mChartView->setRenderHint(QPainter::Antialiasing);
    mChartView->setRubberBand(QChartView::RectangleRubberBand);
    chartLayout->addWidget(mChartView);

    mChart = new QtCharts::QChart();
    mChartView->setChart(mChart);

    mLeftAxis = new QtCharts::QValueAxis();
    mLeftAxis->setMax(3.0f);
    mLeftAxis->setMin(-3.0f);
    mChart->addAxis(mLeftAxis, Qt::AlignLeft);

    mRightAxis = new QtCharts::QValueAxis();
    mRightAxis->setMax(1.0f);
    mRightAxis->setMin(-1.0f);
    mChart->addAxis(mRightAxis, Qt::AlignRight);

    mBottomAxis = new QtCharts::QValueAxis();
    mBottomAxis->setMax(mXRange);
    mBottomAxis->setMin(0.0f);
    mChart->addAxis(mBottomAxis, Qt::AlignBottom);

    QHBoxLayout *chartSetLayout = new QHBoxLayout();
    chartSetLayout->setAlignment(Qt::AlignLeft);
    layout->addLayout(chartSetLayout, Qt::AlignLeft);

    // range set ui
    QRegExp regx("[+-]{0,}[0-9.]+$");
    QValidator* validator = new QRegExpValidator(regx, this);

    chartSetLayout->addWidget(new QLabel("X Range:"));
    mXRangeEdit = new QLineEdit(this);
    mXRangeEdit->setValidator(validator);
    mXRangeEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mXRangeEdit->setText(QString("%0").arg(mXRange));
    chartSetLayout->addWidget(mXRangeEdit);

    QPushButton *updateXRangeBtn = new QPushButton("Set");
    updateXRangeBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    chartSetLayout->addWidget(updateXRangeBtn);
    connect(updateXRangeBtn, &QPushButton::clicked, this, &RunTimeChart::updateXRange);

    chartSetLayout->addWidget(new QLabel("Y Min:"));
    mYMinEdit = new QLineEdit("-3.0", this);
    mYMinEdit->setValidator(validator);
    mYMinEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    chartSetLayout->addWidget(mYMinEdit);

    chartSetLayout->addWidget(new QLabel("Y Max:"));
    mYMaxEdit = new QLineEdit("3.0", this);
    mYMaxEdit->setValidator(validator);
    mYMaxEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    chartSetLayout->addWidget(mYMaxEdit);

    QPushButton *updateYRangeBtn = new QPushButton("Set");
    updateYRangeBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    chartSetLayout->addWidget(updateYRangeBtn);
    connect(updateYRangeBtn, &QPushButton::clicked, this, &RunTimeChart::updateYRange);

    // QPushButton *startStopBtn = new QPushButton("Start");
    // startStopBtn->setCheckable(true);
    // chartSetLayout->addWidget(startStopBtn);
    // connect(startStopBtn, &QPushButton::clicked, [this, startStopBtn]{
    //     mIsStart = startStopBtn->isChecked();
    //     emit start(mIsStart);
    // });

    QPushButton *resetBtn = new QPushButton("Reset");
    chartSetLayout->addWidget(resetBtn);
    connect(resetBtn, &QPushButton::clicked, [this] {
        mLeftAxis->setMax(3.0f);
        mLeftAxis->setMin(-3.0f);
        mRightAxis->setMax(1.0f);
        mRightAxis->setMin(-1.0f);
        mBottomAxis->setMax(mXRange);
        mBottomAxis->setMin(0.0f);
    });

    QPushButton *clearCallOutBtn = new QPushButton("Clear");
    chartSetLayout->addWidget(clearCallOutBtn);
    connect(clearCallOutBtn, &QPushButton::clicked, [this]{
        for(int i = 0; i < m_callouts.size(); i++)
        {
            delete m_callouts.at(i);
        }
        m_callouts.clear();
    });

    mStartTime = QDateTime::currentMSecsSinceEpoch();

    mLoadFilerTimer = new QTimer();
    connect(mLoadFilerTimer, &QTimer::timeout, this, &RunTimeChart::timerLoadData);
}

void RunTimeChart::addChannal(QString label, QColor color, Qt::AlignmentFlag align)
{
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries(mChart);
    QPen pen;
    pen.setWidthF(1.0);
    pen.setColor(color);
    series->setPen(pen);
    mChart->addSeries(series);
    series->setName(label);
    series->attachAxis(mBottomAxis);

    switch (align)
    {
    case Qt::AlignLeft:
        series->attachAxis(mLeftAxis);
        break;
    case Qt::AlignRight:
        series->attachAxis(mRightAxis);
        break;
    default:
        series->attachAxis(mLeftAxis);
        break;
    }

    mSeriesList.append(series);
    connect(series, &QtCharts::QLineSeries::hovered, this, &RunTimeChart::hoveredLine);
    connect(series, &QtCharts::QLineSeries::clicked, this, &RunTimeChart::keepCallOut);
}

void RunTimeChart::setYRange(float min, float max)
{
    mLeftAxis->setMax(max);
    mLeftAxis->setMin(min);
}

void RunTimeChart::updateData(int ch, float val)
{
    if(!isStart()) return;
    QtCharts::QLineSeries *ser = mSeriesList.at(ch);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();
    qreal x = (t - mStartTime) / 1000.0f;
    ser->append(x, val);

    qreal min = x - mXRange;
    mBottomAxis->setMax(x);
    mBottomAxis->setMin(min);
    while(ser->pointsVector().at(0).x() < min)
    {
        ser->removePoints(0, 1);
    }

    while(ser->pointsVector().at(0).x() < min)
    {
        ser->removePoints(0, 1);
    }
}

void RunTimeChart::updateXRange()
{
    mXRange = mXRangeEdit->text().toFloat();

    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();
    qreal x = (t - mStartTime) / 1000.0f;
    mBottomAxis->setMax(x);
    mBottomAxis->setMin(x - mXRange);
}

void RunTimeChart::updateYRange()
{
    mLeftAxis->setMax(mYMaxEdit->text().toFloat());
    mLeftAxis->setMin(mYMinEdit->text().toFloat());
}

void RunTimeChart::clearAllData()
{

}

void RunTimeChart::keepCallOut()
{
    m_callouts.append(m_tooltip);
    m_tooltip = new Callout(mChart);
}

void RunTimeChart::hoveredLine(QPointF point, bool state)
{
    if (m_tooltip == 0)
        m_tooltip = new Callout(mChart);

    if (state) {
        m_tooltip->setText(QString("X: %1 \nY: %2 ").arg(point.x()).arg(point.y()));
        m_tooltip->setAnchor(point);
        m_tooltip->setZValue(11);
        m_tooltip->updateGeometry();
        m_tooltip->show();
    } else {
        m_tooltip->hide();
    }
}

void RunTimeChart::uploadFile(const QString &f)
{
    QFile file(f);
    file.open(QIODevice::ReadOnly);
    if (file.isOpen())
    {
        // 清空全部通道
        for (auto channal = mSeriesList.begin(); channal != mSeriesList.end(); channal++)
        {
            (*channal)->clear();
        }

        // 首行为表头，先读出来
        file.readLine();
        // 循环读出并加入
        double first_x = 0.0;
        double finnal_x = 0.0;
        int cnt = 0;
        while (!file.atEnd())
        {
            QByteArray lines = file.readLine();
            QStringList vals = QString(lines).split(',');
            auto itor = vals.begin();
            double x = itor->toDouble();
            finnal_x = x;
            if(!cnt) {first_x = x; cnt = 1;}
            std::cout << "load data:" << itor->toStdString() << std::endl;
            
            itor++;
            for (auto channal = mSeriesList.begin(); channal != mSeriesList.end() && itor != vals.end();
                 itor++, channal++)
            {
                (*channal)->append(QPointF(x, itor->toDouble()));
            }
        }

        // 设置X轴范围
        mBottomAxis->setMax(finnal_x);
        mBottomAxis->setMin(first_x);
        file.close();
    }
}

void RunTimeChart::timerLoadData()
{
    if(mLoadFile)
    {
        // 循环读出并加入
        double first_x = 0.0;
        double finnal_x = 0.0;
        int cnt = 0;
        while (cnt < 1000)
        {
            // 判断是否抵达文件末尾
            if(mLoadFile->atEnd())
            {
                mLoadFilerTimer->stop();
                mLoadFile->close();
                delete mLoadFile;
                mLoadFile = nullptr;
            }

            QByteArray lines = mLoadFile->readLine();
            QStringList vals = QString(lines).split(',');
            auto itor = vals.begin();
            double x = itor->toDouble();
            finnal_x = x;
            if(!cnt) {first_x = x; cnt = 1;}
            std::cout << "load data:" << itor->toStdString() << "\r";
            
            itor++;
            for (auto channal = mSeriesList.begin(); channal != mSeriesList.end() && itor != vals.end();
                 itor++, channal++)
            {
                (*channal)->append(QPointF(x, itor->toDouble()));
            }
        }

        // 设置X轴范围
        mBottomAxis->setMax(finnal_x);
        mBottomAxis->setMin(first_x);
    }
}
