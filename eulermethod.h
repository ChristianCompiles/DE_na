#ifndef EULERMETHOD_H
#define EULERMETHOD_H

#include <iostream>
#include <QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>

typedef struct float_1d_t
{
    size_t n0;
    float* ptr;
};

class eulerMethod
{
private:
    float_1d_t t;
    float_1d_t x;

    void disp()
    {
        QLineSeries *series = new QLineSeries();

        // for (size_t i = 0; i < t.n0; ++i)
        // {
        //     series->append(x.ptr[i], t.ptr[i]);
        // }

        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("Simple line chart example");

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    }

public:
    eulerMethod(float (*funcHandle)(float, float), float t0, float x0, float tmax, int npts);
    ~eulerMethod();
};

#endif // EULERMETHOD_H
