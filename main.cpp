#include "mainwindow.h"
#include "eulermethod.h"
#include <QApplication>

float xprime(float x, float t)
{
    return 1 + (x * x) + (t * t * t);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    float (*functHandle)(float, float);

    functHandle = xprime;
    float t0 = 1.0f;
    float x0 = -4.0f;
    float tmax = 2;
    float npts = 10;

    MainWindow w(nullptr, functHandle, t0, x0, tmax, npts);
    w.show();
    return a.exec();
}

