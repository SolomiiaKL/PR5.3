// Lab_05_3.cpp
// < Клак Соломія >
// Лабораторна робота № 5.3
// Варіант 14
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double t(const double x);
double z(const double f);

int main()
{
    double fp, fk;  
    int n;          

    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n = ";  cin >> n;

    if (n <= 0)
    {
        cout << "Error: n must be positive" << endl;
        return 1;
    }

    double df = (fk - fp) / n;  

    cout << "Table of values of z(f) = "
        << "t(f^2) + 2t(2f+1) + sqrt(t(1))" << endl;
    cout << "---------------------------" << endl;
    cout << "|" << setw(10) << "f" << " |"
        << setw(12) << "z(f)" << " |" << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        double f = fp + i * df;  
        double zf = z(f);

        cout << "|" << setw(10) << fixed << setprecision(5) << f
            << " |" << setw(12) << setprecision(6) << zf << " |" << endl;
    }
    cout << "---------------------------" << endl;

    return 0;
}

double t(const double x)
{
    if (fabs(x) >= 1)
        return (cos(x) + 1) / (exp(x) + sin(x) * sin(x));
    else
    {
        double a = x;
        double S = a;

        for (int j = 1; j <= 5; j++)
        {
            double R = -x * x / ((2.0 * j) * (2.0 * j + 1));
            a *= R;
            S += a;
        }
        return S;
    }
}

double z(const double f)
{
    return t(f * f) + 2 * t(2 * f + 1) + sqrt(t(1));
}
