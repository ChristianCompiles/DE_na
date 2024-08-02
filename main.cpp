#include <iostream>
#include <vector>

// Euler's method

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


        void print()
        {
            for (size_t i = 0; i < t.n0; ++i)
            {
                std::cout << x.ptr[i] << " ";
            }
            std::cout << std::endl;

            for (size_t i = 0; i < t.n0; ++i)
            {
                std::cout << t.ptr[i] << " ";
            }
            std::cout << std::endl;
        }

    public:

    eulerMethod(float (*funcHandle)(float, float), float t0, float x0, float tmax, int npts)
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
        print();
    }

    
    ~eulerMethod()
    {
        if (t.ptr != nullptr)
        {
            delete[] t.ptr;
            delete[] x.ptr;
        }
    }

};

float xprime(float x, float t)
{
    return 1 + (x * x) + (t * t * t);
}

int main()
{
    float (*functHandle)(float, float);

    functHandle = xprime;
    float t0 = 1.0f;
    float x0 = -4.0f;
    float tmax = 2;
    float npts = 10;

    eulerMethod eM(functHandle, t0, x0, tmax, npts);

    return 0;
}