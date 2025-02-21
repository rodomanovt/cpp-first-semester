#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void one()
{
    float m, s, n, p, r;
    cout << "S = ";
    cin >> s;
    cout << "p = ";
    cin >> p;
    cout << "n = ";
    cin >> n;
    r = p/100;
    if (s >= 0 && p >= 0 && n >= 0)
    {
        m = ((s * r) * pow(1+r, n)) / (12 * (pow(1+r, n) - 1));
    }
    cout << "m = " << m << endl;
}


void two()
{
    float m0, m, s, n, p, r, eps;
    cout << "S = ";
    cin >> s;
    cout << "m0 = ";
    cin >> m0;
    cout << "n = ";
    cin >> n;
    eps = 0.01;
    if (s >= 0 && m0 >= 0 && n >= 0)
    {    for (p = 1; p <= 100; p++)
        {
            r = p/100;
            m = ((s * r) * pow(1+r, n)) / (12 * (pow(1+r, n) - 1));
            if (abs(m - m0) < eps)
            {
                cout << "p = " << p;
                break;
            }
        }
    }
}


void three()
{
    char text[20];
    ifstream file("3-3.txt");
    file.getline(text, 20);
    file.close();
    cout << text;
}


void four()
{
    string text, digits;
    const string c = "qwertyuiopasdfghjklzxcvbnm[]{};':,.<>";
    int i;
    ifstream file("3-4.txt");
    file >> text;
    file.close();
    for (i = 0; i < text.size(); i++)
    {
        if (c.find(text[i]) == string::npos)
        {
            digits = digits + text[i];
        }
    }
    cout << digits << endl;
}


void five()
{
    string s;
    cout << "Введите строку: ";
    cin >> s;
    int i, j;
    for (i = 0; i < s.size(); i++)
    {
        for (j = 0; j < s.size()-1; j++)
        {
            if (s[j] > s[j+1])
            {
                swap(s[j+1], s[j]);
            }
        }
    }
    cout << s;
}


int main()
{
    five();
    return 0;
}