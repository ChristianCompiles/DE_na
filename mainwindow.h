#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eulermethod.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    eulerMethod* eM;

public:
    MainWindow(QWidget *parent = nullptr, float (*funcHandle)(float, float) = nullptr, float t0 = 0.0f, float x0 = 0.0f, float tmax=0.0f, int npts=0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
