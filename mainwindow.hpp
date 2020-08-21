#ifndef _MAIN_WINDOW_
#define _MAIN_WINDOW_

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QTabWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTabWidget *mModelTabWidget;
};

#endif
