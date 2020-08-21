#include "mainwindow.hpp"
#include "can_monitor.hpp"
#include "protocol_tool.hpp"
#include "pid_tool.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
  , mModelTabWidget(new QTabWidget(this))
{
    QWidget *w = new QWidget(this);
    setCentralWidget(w);
    setMinimumSize(640, 420);

    QVBoxLayout *centerLayout = new QVBoxLayout(w);
    centerLayout->addWidget(mModelTabWidget);

    // mModelTabWidget->addTab(new CanMonitor(mModelTabWidget), "CAN Monitor");
    // mModelTabWidget->addTab(new ProtocolTool(mModelTabWidget), "Protocol");
    mModelTabWidget->addTab(new PidTool(mModelTabWidget), "PIDTool");

}

MainWindow::~MainWindow()
{

}