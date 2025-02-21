#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void one()
{
    cout << "Тимофей" << endl;
}


void two()
{
    float a;
    float b;
    cout << "Введите число а: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;
    cout << "Сумма = " << a+b << endl;
    cout << "Разность = " << abs(a-b) << endl;
    cout << "Произведение = " << a*b << endl;
    if (b != 0){
        cout << "Частное = " << a/b << endl;
    }
    else{
        cout << "Деление на ноль невозможно";
    }
}


void three()
{
    float b;
    float c;
    cout << "Введите число b: ";
    cin >> b;
    cout << "Введите число c: ";
    cin >> c;
    if (b == 0){
        if (c == 0) {
            cout << "Бесконечное число решений";
        }
        else{
            cout << "Нет решений";
        }
    }
    else{
        cout << "x = " << ((0-c)/b) << endl;
    }
}


void four()
{
    float a;
    float b;
    float c;
    float D;
    cout << "Введите число a: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;
    cout << "Введите число c: ";
    cin >> c;
    if (a == 0){
        if (b == 0){
            if (c == 0) {
                cout << "Бесконечное число решений";
            }
            else{
                cout << "Нет решений";
            }
        }
        else{
            cout << "x = " << ((0-c)/b) << endl;
        }
    }
    else{
        D = pow(b, 2) - 4*a*c;
        if (D == 0){
            cout << "X = " << (0-b)/(2*a) << endl;
        }
        else if (D >= 0)
        {
            cout << "X1 = " << ((0-b)+std::sqrt(D))/(2*a) << endl;
            cout << "X2 = " << ((0-b)-std::sqrt(D))/(2*a) << endl;
        }
        else{
                cout << "Нет решений";
            }
    }
}


void five()
{
    string daytime;
    string curtains;
    string lamp;
    cout << "Сейчас день?" << endl;
    cin >> daytime;
    cout << "Шторы раздвинуты?" << endl;
    cin >> curtains;
    cout << "Лампа включена?" << endl;
    cin >> lamp;
    if ((daytime == "да" and curtains == "да") or lamp == "да"){
        cout << "В комнате светло" << endl;
    }
    else{
        cout << "В комнате темно" << endl;
    }
}


int main()
{
    four();
    return 0;
}