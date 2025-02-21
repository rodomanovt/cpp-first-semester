// Вариант 1
// Найти количество натуральных чисел, не превосходящих заданного n и делящихся на каждую из своих цифр.


#include <iostream>
#include <unordered_set>
#include <random>
#include <chrono>
#include <format>
using namespace std;


int algorithm(int n, int& C, int& M, bool reqDetaliedSolution){
    int cnt = 0; // счетчик чисел, подходящих под условие задачи
    for (int x = 1; x <= n; x++){
        C += 1;
        if(reqDetaliedSolution) cout << "Рассмотрим число " << x << endl;

        unordered_set<char> seen = {};
        string sx = "";
        for (char c : to_string(x)){

            C += 1;
            if (c != '0'){
                seen.insert(c); // собираем сет чаров
                M += 1;
            }
        }
        for (char c: seen){
            sx += c; // собираем строку c нужными цифрами
            M += 1;
            
        }
        if (reqDetaliedSolution) cout << "его ненулевые цифры:" << sx << endl;

        cnt += 1; // всегда увеличиваем на 1; если число не подойдет под условие, отнимем 1
        for (char c : sx){
            int ci = c - '0'; // перевод чара в инт через таблицу аскии

            C += 1;
            if (x % ci != 0){
                if (reqDetaliedSolution) cout << "число не поделилось на цифру " << ci << endl;
                cnt -= 1; // отнимаем 1, если число не подошло (см на 5 строчек выше)
                break; // если число не поделилось на какую-то цифру то скип
            }
            
        }
        if (reqDetaliedSolution)
        if (reqDetaliedSolution) cout << "счетчик: " << cnt << "\n__________________" << endl;

    }
    return cnt;
}

int main(){
    cout << "Практическая работа №1. 'Теоретическая сложность алгоритма'. Родоманов Тимофей " << endl;
    cout << "Выберите способ ввода числа:" << endl;
    cout << "1) Вручную" << endl;
    cout << "2) Случайное число от 1 до 1 000 000" << endl;
    int choice, n;
    bool reqDetailedSolution = false;
    cin >> choice;
    if (choice == 1){
        cout << "Введите число: ";
        cin >> n;
        if (n <= 1000) reqDetailedSolution = true;
    }
    else {
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> range(1, 1000000);
        n = range(eng);
        cout << "Входные данные: " << n << endl;
    }

    int C = 0; // счетчик сравнений
    int M = 0; // счетчик перемещений

    auto start_timing = chrono::high_resolution_clock::now();
    int result = algorithm(n, C, M, reqDetailedSolution);
    auto end_timing = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_timing-start_timing;

    cout << "Результат: " << result << endl;
    cout << C << " сравнений, " << M << " перемещений, C + M = " << C+M << endl;;
    //cout << format("Время работы алгоритма: {:8} секунд", end_timing-start_timing);
    cout << "Время работы программы: " << duration.count();
    return 0;
}