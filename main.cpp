#include <iostream>
#include <QApplication>
#include "mainwindow.hpp"
#include "ros_helper.hpp"
#include <QHash>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    RosHelper::getInstance(argc, argv, "tool_box");

    MainWindow w;

    w.show();

    return app.exec();
}