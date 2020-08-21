#ifndef _CAN_MONITOR_
#define _CAN_MONITOR_

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

#include <iostream>

class CanMonitor : public QWidget
{
    Q_OBJECT

public:
    CanMonitor(QWidget *parent = nullptr);
    ~CanMonitor();


private:
    QTableWidget *mInfoTableWidget;
    QProgressBar *mCanFrameLoadRateBar;

    void __change2RawModel();
    void __change2DetailModel();

public slots:
    void changeMonitorModel(int index);

};


#endif // _CAN_MONITOR_