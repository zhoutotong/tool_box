#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QDialog>
#include <QFileDialog>
#include <QSaveFile>
#include <QMessageBox>
#include <deque>

#include <fstream>
#include "runtimechart.h"

#include "ros_helper/ros_helper.hpp"

class PidTool : public QWidget
{
    Q_OBJECT
private:

    typedef struct _DataBufferItem {
        qint64 stamp;
        double realSpeed;
        double setSpeed;
        double realThro;
        double realBrake;
        double slope;
        double engineSpeed;
        _DataBufferItem(double st, double rs, double ss, double rt, double rb, double sl, double es) :\
        stamp(st), realSpeed(rs), setSpeed(ss), realThro(rt), realBrake(rb), slope(sl), engineSpeed(es){}
    } DataBufferItem;
    using DataBuffer = std::vector<DataBufferItem>;

public:
    explicit PidTool(QWidget *parent = nullptr);
    ~PidTool();

private:
    enum DataDefines {
        MAX_BUF_SIZE = 24,
        MAX_DATA_SIZE = 100 * 60 * 60,
    };

    RunTimeChart *mChartLeft;
    QPushButton *mEnableCtlBtn;
    QPushButton *mSaveBtn;
    QPushButton *mLoadBtn;

    QTimer *dataRecTimer;

    qint64 mStartTime;

    std::deque<DataBuffer*> mDatas;

    bool mIsSaving;

public slots:

    void start();
    void updateData();
    void saveData();
    void loadData();

    void ctlThro(int thro);
};