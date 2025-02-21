#include <iostream>
#include <cstdlib>
#include <cmath>
#include <typeinfo>
using namespace std;


void one()
{
    float R, r, h, l;
    cout << "R = ";
    cin >> R;
    cout << "r = ";
    cin >> r;
    cout << "h = ";
    cin >> h;
    l = sqrt(pow(R-r, 2) + h*h);
    if ((h > 0) && (r > 0) && (R > 0) && (r != R))
    {
        cout << "V = " << (3.14 * h/3 * (R*R + R*r + r*r)) << endl;
        cout << "S = " << (3.14 * (R*R + (r + R) * l + r*r)) << endl;
    }
    else
    {
        cout << "Усеченный конус с такими параметрами не существует";
    }
}


void two()
{
    float x, a;
    cout << "x = ";
    cin >> x;
    cout << "a = ";
    cin >> a;
    if (abs(x) < 1)
    {
        if (x != 0)
        {
            cout << "w = " << a * log(abs(x));
        }
        else
        {
            cout << "Функция не определена";
        }
    }
    else
    {
        if ((a - x*x) >= 0)
        {
           cout << "w = " << sqrt(a - x*x); 
        }
        else
        {
            cout << "Функция не определена";
        }
    }
}


void three()
{
    float x, y, b;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "b = ";
    cin >> b;
    if ((b - y) > 0 && (b - x) >= 0)
    {
        cout << "z = " << log(b - y) * sqrt(b - x);
    }
    else
    {
        cout << "Функция не определена";
    }
}


bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}


void four()
{
    int i, n;
    string m;
    cout << "N = ";
    cin >> m;
    if (is_digits(m))
    {
        n = stoi(m);
        for (i=n; i <= n+9; i++)
        {
        cout << i << endl;
        }
    }
}


void five()
{
    float x, y;
    x = -4;
    cout << "x y" << endl;
    while (x <= 4)
    {
        if (x - 1 == 0)
        {
            cout << "x = " << x << " Функция не определена" << endl;
        }
        else
        {
            y = (x*x - 2*x + 2) / (x - 1);
            cout << "x = " << x << " y = " << y << endl;
        }
        x = x + 0.5;
    }
}


int main()
{
    four();
    return 0;
}