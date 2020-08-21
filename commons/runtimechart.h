#ifndef RUNTIMECHART_H
#define RUNTIMECHART_H

#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QRegExp>
#include <QRegExpValidator>
#include <QValidator>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

#include <QTimer>
#include <QTime>
#include <QDate>
#include <QtMath>
#include <QList>

#include <QFile>

#include <iostream>

#include "callout.h"

class RunTimeChart : public QWidget
{
    Q_OBJECT
public:
    explicit RunTimeChart(QWidget *parent = nullptr);
    void addChannal(QString label, QColor color, Qt::AlignmentFlag align = Qt::AlignLeft);
    inline int numOfChannal() { return mSeriesList.size(); }

    void setStart(const bool &run) { mIsStart = run; }
    bool isStart() { return mIsStart; }
    void setYRange(float min, float max);

    void uploadFile(const QString &f);
private:
    QtCharts::QChartView *mChartView;
    QtCharts::QChart *mChart;

    QtCharts::QValueAxis *mLeftAxis;
    QtCharts::QValueAxis *mRightAxis;
    QtCharts::QValueAxis *mBottomAxis;

    QTimer *mTimer;
    qint64 mStartTime;
    QTime *mTime;

    QLineEdit *mXRangeEdit;
    QLineEdit *mYMaxEdit;
    QLineEdit *mYMinEdit;
    qreal mXRange;

    QList<QtCharts::QLineSeries*> mSeriesList;

    bool mIsStart;

    QFile *mLoadFile;
    QTimer *mLoadFilerTimer;

    Callout *m_tooltip;
    QList<Callout *> m_callouts;

public slots:
    void updateData(int ch, float val);
    void updateXRange();
    void updateYRange();
    void clearAllData();
    void keepCallOut();
    void hoveredLine(QPointF point, bool state);
    void timerLoadData();

signals:
    void start(bool);

};

#endif // RUNTIMECHART_H
