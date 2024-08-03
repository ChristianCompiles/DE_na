#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, float (*funcHandle)(float, float), float t0, float x0, float tmax, int npts)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    eM = new eulerMethod(funcHandle, t0, x0, tmax, npts);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete eM;
}
