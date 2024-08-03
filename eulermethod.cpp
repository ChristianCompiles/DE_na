#include "eulermethod.h"
eulerMethod::eulerMethod(float (*funcHandle)(float, float), float t0, float x0, float tmax, int npts)
{
    int n = npts - 1;
    float h = (tmax - t0) / n;

    t.n0 = npts;
    x.n0 = npts;

    t.ptr = new float[t.n0];
    x.ptr = new float[x.n0];

    t.ptr[0] = t0;
    x.ptr[0] = x0;

    for (size_t k = 0; k < n; ++k)
    {
        t.ptr[k + 1] = t.ptr[k] + h;
        x.ptr[k + 1] = x.ptr[k] + h * funcHandle(x.ptr[k], t.ptr[k]);
    }
    disp();
}

eulerMethod::~eulerMethod()
{
    if (t.ptr != nullptr)
    {
        delete[] t.ptr;
        delete[] x.ptr;
    }
}
float xprime(float x, float t)
{
    return 1 + (x * x) + (t * t * t);
}
