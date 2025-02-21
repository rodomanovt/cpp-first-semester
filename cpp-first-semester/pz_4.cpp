#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// vvvvvvv 1 номер vvvvvvv

void one()
{
    ofstream fout("4-1.txt");
    for (int i = 1; i <= 10; i++)
    {
        int n;
        cout << "Введите " << i << "-е число: ";
        cin >> n;
        fout << n << endl;
    }
    fout.close();

    ifstream fin("4-1.txt");
    string s;
    int res = 0;
    while (getline(fin, s))
    {
        res = res + stoi(s);
    }
    cout << res;
    fin.close();
}

// ^^^^^^^ 1 номер ^^^^^^^
// vvvvvvv 2 номер vvvvvvv

int sign(float x)
{
    if (x > 0){
        return 1;
    }
    else if (x == 0){
        return 0;
    }
    else if (x < 0){
        return -1;
    }
}

void two()
{
    float x;
    cout << "Введите число: ";
    cin >> x;
    cout << sign(x);
}

// ^^^^^^^ 2 номер ^^^^^^^
// vvvvvvv 3 номер vvvvvvv

void rectangle()
{
    float a, b;
    cout << "Одна сторона: ";
    cin >> a;
    cout << "Вторая сторона: ";
    cin >> b;
    if (a > 0 && b > 0)
    {
        cout << "S = " << a*b << endl;
    }
    else
    {
        cout << "Прямоугольник не существует" << endl;
    }
}

void triangle()
{
    float a, b, c, p;
    cout << "Одна сторона: ";
    cin >> a;
    cout << "Вторая сторона: ";
    cin >> b;
    cout << "Третья сторона: ";
    cin >> c;
    p = (a+b+c)/2;
    if (b + c > a && a + b > c && a + c > b)
    {
        cout << "S = " << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
    }
    else
    {
        cout << "Треугольник не существует" << endl;
    }
}

void circle()
{
    float r;
    cout << "Радиус: ";
    cin >> r;
    if (r > 0)
    {
        cout << "S = " << 3.14*pow(r, 2) << endl;
    }
    else
    {
        cout << "Круг не существует";
    }
}

void three()
{
    char sel;
    cout << "Фигура: ";
    cin >> sel;
    switch (sel)
    {
        case 'r':
            rectangle();
            break;
        case 't':
            triangle();
            break;
        case 'c':
            circle();
            break;
    }
}


// ^^^^^^^ 3 номер ^^^^^^^
// vvvvvvv 4 номер vvvvvvv


void four()
{
    for (int r = 0; r <= 4; r++)
    {
        for (int s = 0; s <= 12; s++)
        {
            cout << "*";
        }
        for (int u = 0; u <= 15; u++)
        {
            cout << "_";
        }
        cout << endl;
    }
    for (int r = 0; r <= 4; r++)
    {
        for (int u = 0; u <= 28; u++)
        {
            cout << "_";
        }
        cout << endl;
    }
}

// ^^^^^^^ 4 номер ^^^^^^^
// vvvvvvv 5 номер vvvvvvv

void five()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << ". ";
        }
        cout << "| ";
        for (int j = 0; j < 10; j++)
        {
            cout << ". ";
        }
        cout << endl;
    }
    cout << "# # # . . . . . . . | . # # # # . . . . ." << endl;
    cout << "# # # # . . . . . . | # # # # # # . . . ." << endl;
    cout << "- - - # # - - - - # # # - - - - # # - - -" << endl;
    cout << ". . . . # # # # # # # . . . . . . # # # #" << endl;
    cout << ". . . . . # # # # . | . . . . . . . # # #" << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << ". ";
        }
        cout << "| ";
        for (int j = 0; j < 10; j++)
        {
            cout << ". ";
        }
        cout << endl;
    }
}

// ^^^^^^^ 5 номер ^^^^^^^
// vvvvvvv 6 номер vvvvvvv

bool valid_rim(string rim){ // работает не во всех случаях
    bool flag = true;
    vector<string> forbidden = {"IIII", "VV", "XXXX", "LL", "CCCC", "DD", "MMMM", "IIX", "IIV", "IIL", 
    "XXL", "IIC", "XXC", "IID", "XXD", "CCD",
    "IIM", "XXM", "CCM", "VIX", "VIV", "VIL", "XIL", "VIC", "XIC", "LIC", "VXC", "XXC", "LXC", "VID", 
    "XID", "LID", "VXD", "XXD", "LXD", "CID",
    "CXD", "VIM", "XIM", "LIM", "VXM", "XXM", "LXM", "CIM", "CXM"};
    for (string el : forbidden){
        if (rim.find(el) != string::npos){
            flag = false;
            break;
        }
    }
    return flag;
}

void six()
{
    string rim;
    bool flag = true;
    vector<int> digit_values = {};
    cout << "Введите римское число: ";
    cin >> rim;
    int res = 0;
    if (valid_rim(rim)){
        for (char d : rim){
            switch (d){
                case 'I':
                    digit_values.push_back(1);
                    break;
                case 'V':
                    digit_values.push_back(5);
                    break;
                case 'X':
                    digit_values.push_back(10);
                    break;
                case 'L':
                    digit_values.push_back(50);
                    break;
                case 'C':
                    digit_values.push_back(100);
                    break;
                case 'D':
                    digit_values.push_back(500);
                    break;
                case 'M':
                    digit_values.push_back(1000);
                    break;
            }
        }
        if (digit_values.size() > 1){
            for (int i = digit_values.size()-1; i >= 0; i-=1){
                if (digit_values[i] < digit_values[i+1]){
                    if (digit_values[i] == 1 || digit_values[i] == 10 || digit_values[i] == 100){
                        res = res - digit_values[i];
                        continue;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else{
                    res = res + digit_values[i];
                }
            }
        }
        else{
            res = digit_values[0];
        }
    }
    else{
        flag = false;
    }
    if (flag){
        cout << res << endl;
    }
    else{
        cout << "Такое римское число не существует" << endl;
    }
}

// ^^^^^^^ 6 номер ^^^^^^^
// vvvvvvv 7 номер vvvvvvv

int gen(int s, int m, int i, int c){
    if (s == 1){
        return 1;
    }
    else{
        return ((m * gen(s-1, m, i, c) + i) % c);
    }
}


void seven()
{
    for (int s = 1; s < 10; s++){
        cout << gen(s, 37, 3, 64) << endl;
    }
    for (int s = 1; s < 10; s++){
        cout << gen(s, 25173, 13849, 65537) << endl;
    }
}

// ^^^^^^^ 7 номер ^^^^^^^
// vvvvvvv 8 номер vvvvvvv

void eight()
{
    vector<vector<float>> A = {vector<float> {5, 2, 0, 10},
                            vector<float> {3, 5, 2, 5}, 
                            vector<float> {20, 0, 0, 0}};

    vector<vector<float>> B = {vector<float> {1.2, 0.5},
                                vector<float> {2.8, 0.4},
                                vector<float> {5.0, 1.0},
                                vector<float> {2.0, 1.5}};
    
    vector<vector<float>> C(A.size(), vector<float>(B[0].size(), 0));
    for (int i = 0; i < C.size(); i++){
        for (int j = 0; j < C.size(); j++){
            for (int k = 0; k < B.size(); k++){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
    cout << "1) ";
    float first = C[0][0]+C[0][1];
    float second = C[1][0]+C[1][1];
    float third = C[2][0]+C[2][0];
    if (first > second){
        if (first > third){
            cout << "1 - max; ";
        }
        else{
            cout << "3 - max; ";
        }
    }
    else{
        if (second > third){
            cout << "2 - max; ";
        }
        else{
            cout << "3 - max; ";
        }
    }
    if (first < second){
        if (first < third){
            cout << "1 - min" << endl;
        }
        else{
            cout << "3 - min" << endl;
        }
    }
    else{
        if (second < third){
            cout << "2 - min" << endl;
        }
        else{
            cout << "3 - min" << endl;
        }
    }

    cout << "2) ";
    first = C[0][1];
    second = C[1][1];
    third = C[2][0];
    if (first > second){
        if (first > third){
            cout << "1 - max; ";
        }
        else{
            cout << "3 - max; ";
        }
    }
    else{
        if (second > third){
            cout << "2 - max; ";
        }
        else{
            cout << "3 - max; ";
        }
    }
    if (first < second){
        if (first < third){
            cout << "1 - min" << endl;
        }
        else{
            cout << "3 - min" << endl;
        }
    }
    else{
        if (second < third){
            cout << "2 - min" << endl;
        }
        else{
            cout << "3 - min" << endl;
        }
    }

    cout << "3) ";
    float summa = 0;
    for (int i = 0; i < C.size(); i++){
        for (int j = 0; j < C[0].size(); j++){
            summa = summa + C[i][j];
        }
    }
    cout << summa << endl;

    cout << "4) ";
    summa = 0;
    for (int i = 0; i < C.size(); i++){
        summa = summa + C[i][1];
    }
    cout << summa << endl;

    cout << "5) ";
    summa = 0;
    for (int i = 0; i < C.size(); i++){
        summa = summa + C[i][0];
    }
    cout << summa << endl;
}

// ^^^^^^^ 8 номер ^^^^^^^
// vvvvvvv 9 номер vvvvvvv

bool valid_notation(string num, int notation){
    int min_valid_notation = 17;
    for (int j = 0; j < num.size()-1; j++)
    {
        if (num[j] < num[j+1])
        {
            swap(num[j+1], num[j]);
        }
    }
    switch (num[0]){
        case '1': 
            min_valid_notation = 2;
            break;
        case '2': 
            min_valid_notation = 3;
            break;
        case '3': 
            min_valid_notation = 4;
            break;
        case '4': 
            min_valid_notation = 5;
            break;
        case '5': 
            min_valid_notation = 6;
            break;
        case '6': 
            min_valid_notation = 7;
            break;
        case '7': 
            min_valid_notation = 8;
            break;
        case '8': 
            min_valid_notation = 9;
            break;
        case '9': 
            min_valid_notation = 10;
            break;
        case 'a': 
            min_valid_notation = 11;
            break;
        case 'b': 
            min_valid_notation = 12;
            break;
        case 'c': 
            min_valid_notation = 13;
            break;
        case 'd': 
            min_valid_notation = 14;
            break;
        case 'e': 
            min_valid_notation = 15;
            break;
        case 'f': 
            min_valid_notation = 16;
            break;
    }
    return min_valid_notation <= notation;
}


long long any_to_decimal(string num, int notation){
    vector<int> digit_values = {};
    long long dec_num = 0;
    for (char n: num){
        switch (n){
        case '0':
            digit_values.push_back(0);
            break;
        case '1': 
            digit_values.push_back(1);
            break;
        case '2': 
            digit_values.push_back(2);
            break;
        case '3': 
            digit_values.push_back(3);
            break;
        case '4': 
            digit_values.push_back(4);
            break;
        case '5': 
            digit_values.push_back(5);
            break;
        case '6': 
            digit_values.push_back(6);
            break;
        case '7': 
            digit_values.push_back(7);
            break;
        case '8': 
            digit_values.push_back(8);
            break;
        case '9': 
            digit_values.push_back(9);
            break;
        case 'a': 
            digit_values.push_back(10);
            break;
        case 'b': 
            digit_values.push_back(11);
            break;
        case 'c': 
            digit_values.push_back(12);
            break;
        case 'd': 
            digit_values.push_back(13);
            break;
        case 'e': 
            digit_values.push_back(14);
            break;
        case 'f': 
            digit_values.push_back(15);
            break;
        }
    }
    int power = 0;
    for (int i = digit_values.size()-1; i >= 0; i-=1){
        dec_num = dec_num + digit_values[i]*pow(notation, power);
        power += 1;
    }
    return dec_num;
}


string decimal_to_any(long long decimal, int notation){
    string res = "";
    const string alph = "0123456789abcdef";
    while (decimal > 0){
        res = alph[decimal%notation] + res;
        decimal = decimal / notation;
    }
    return res;
}


void nine()
{
    string num;
    int notation1; int notation2; long long decimal;
    cout << "Введите число: ";
    cin >> num;
    cout << "Его система счисления: ";
    cin >> notation1;
    cout << "Перевести в систему счисления: ";
    cin >> notation2;
    if (valid_notation(num, notation1) && 2 <= notation1 <= 16 && 2 <= notation2 <= 16){
        decimal = any_to_decimal(num, notation1);
        cout << decimal_to_any(decimal, notation2);
    }
    else{
        cout << "value error" << endl;
    }
}

// ^^^^^^^ 9 номер ^^^^^^^
// vvvvvvv запуск vvvvvvv

int main()
{
    six(); // для запуска нужного номера вызываете функцию с названием номера (one, two, ... nine)
    return 0;
}