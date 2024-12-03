#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void print_vector(vector<auto>& s){
    for (auto i : s){
        cout << i << "; ";
    }
    cout << endl;
}


int nod(int a, int b){ // алгоритм Евклида
    while (a != 0 && b != 0){
        if (a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    return (a+b);
}


void one(){
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << nod(a, b) << endl;
}


void two(){
    int n, j;
    cout << "n = ";
    cin >> n;
    vector<int> a = {};
    for (int i = 0; i <= n-1; i++){
        a.push_back(i);
    }
    a[1] = 0;
    for (int m = 2; m < n; m++){
        if (a[m] != 0){
            j = m * 2;
            while (j < n){
                a[j] = 0;
                j = j + m;
            }
        }
        else{
            continue;
        }
    }

    vector<int> res = {};
    for (int el : a){
        if (el != 0){
            res.push_back(el);
        }
    }
    print_vector(res);
}


void three_six(){ // поиск слова минимальной длины
    string word, line, s;
    vector<string> words = {};
    vector<string> lines = {};
    ifstream file("5-3.txt");
    while (getline(file, line)){
        lines.push_back(line);
    }
    file.close();
    for (string line : lines){ // split
        stringstream ss(line);
        while (getline(ss, word, ' ')){
            words.push_back(word);
        }
    }
    int minilen = pow(2, 31) - 1;
    string miniword;
    for (string w : words){
        if (w.size() < minilen){
            minilen = w.size();
            miniword = w;
        }
    }
    cout << "Самое короткое слово " << miniword << " имеет длину " << minilen << endl;
}


void three_twenty(){ // поиск наименее часто встречающегося символа
    string text, line;
    ifstream file("5-3.txt");
    while (getline(file, line)){
        text += line;
    }
    file.close();
    int counter[128] {}; // массив количеств вхождений по аски кодам
    for (char el : text){
        counter[int(el)] += 1;
    }
    char rarest;
    int amount = pow(2, 31)-1;
    for (int i = 0; i < 128; i++){
        if (counter[i] != 0){
            if (counter[i] < amount){
                amount = counter[i];
                rarest = char(i);
            }
        }
    }
    cout << "Самый редкий символ " << rarest << " встречается " << amount << " раз" << endl;
}


double square(double n){
    return pow(n, 2);
}


double fun_a(int n, double x){
    if (n == 1){
        return 0.0;
    }
    if (n == 2){
        return 1.0;
    }
    if (n == 3){
        return x;
    }
    double an = 3 + 1/pow(2, n) * square(
        cos(square(fun_a(n-1, x)) - x*square(fun_a(n-2, x))
        - fun_a(n-3, x)/x)
    );
    if (n > 3){
        return an;
    }
}


void four_six(){ // действия с рекурсивной функцией
    double x, epsilon;
    int j;
    cout << "x = ";
    cin >> x;
    cout << "epsilon = ";
    cin >> epsilon;
    for (int n = 2; n <= 10000; n++){
        if (abs(fun_a(n, x) - fun_a(n-1, x)) < epsilon){
            cout << fun_a(n, x);
            break;
        }
    }
}


string bin(int decimal){
    string res = "";
    string alph = "01";
    while (decimal > 0){
        res = alph[decimal%2] + res;
        decimal = decimal / 2;
    }
    return res;
}


string bin_to_four(string binary){
    string four = "";
    string duo;
    if (binary.size() % 2 != 0){
        binary = "0" + binary;
    }
    for (int i = 0; i < binary.size(); i+=2){
        duo = string(1, binary[i]) + string(1, binary[i+1]);
        if (duo == "00"){four += "0";}
        else if (duo == "01"){
            four += "1";}
        else if (duo == "10"){
            four += "2";}
        else if (duo == "11"){
            four += "3";}
    }
    return four;
}


void four_twenty(){ // массив двоичных чисел f[1:n] перевести в четверичные
    vector<string> f = {};
    int n;
    cout << "n = ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        f.push_back(bin(i));
    }
    print_vector(f);
    vector<string> res = {};
    for (string el : f){
        res.push_back(bin_to_four(el));
    }
    print_vector(res);
}


bool is_prime(int x){
    for(int i = 2; i <= pow(x, 0.5); i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}


void five_six(){ // найти НОД файла и все простые числа
    ifstream fin("5-5-6-nums.txt");
    vector<int> nums = {};
    string s;
    while (getline(fin, s)){
        nums.push_back(stoi(s));
    }
    fin.close();

    vector<int> primes = {}; 
    for (int el: nums){
        if (is_prime(el)){
            primes.push_back(el);
        }
    }

    ofstream fout("5-5-6-primes.txt");
    if (primes.size() > 0){
        for (int prime: primes){
            fout << prime << endl;
        }
    }

    int gcd = nod(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++){
        gcd = nod(gcd, nums[i]);
    }

    cout << "НОД всех чисел: " << gcd << endl;

    cout << "Все числа: ";
    print_vector(nums);
    cout << "Простые числа: ";
    print_vector(primes);
}


string get_number(string el, int number_len){
    string num = "";
    for (int i = el.size()-number_len; i < el.size(); i++){
        num += el[i];
    }
    return num;
}

void five_twenty(){
    int number_len = 7; int cnt = 0; int amount;
    vector<string> phone_nums = {}; //"Илья 6004286", "Саша 1656801", "Ваня 8844828", "Сережа 2244668", "Петя 2166644"
    string s;

    cout << "Длина телефонного номера: ";
    cin >> number_len;
    cout << "Количество номеров: ";
    cin >> amount;
    getline(cin, s); // это не срабатывает
    for (int i = 1; i <= amount; i++){
        cout << i << "-ая строка: ";
        getline(cin, s); // эти начинают срабатывать
        phone_nums.push_back(s);
    }

    ofstream fout("phone.txt");
    if (fout.is_open()){
        for (auto el: phone_nums){
            fout << el << endl;
        }
    }
    fout.close();

    vector<string> sorted_nums = {};
    for(auto el: phone_nums){ // отбираем подходящие под условие
        string num = get_number(el, number_len);
        
        bool flag = true;
        for (auto digit: num){
            if (digit == '1' || digit == '3' || digit == '5' || digit == '7' || digit == '9'){
                flag = false;
                break;
            }
        }
        if (flag){
            sorted_nums.push_back(el);
        }
    }

    for (int i = 0; i < sorted_nums.size(); i++){ // bubble sort
        for (int j = 0; j < sorted_nums.size(); j++){
            if (get_number(sorted_nums[i], number_len) > get_number(sorted_nums[j], number_len)){
                swap(sorted_nums[i], sorted_nums[j]);
            }
        }
    }
    
    ofstream sorted_fout("sorted_phone.txt");
    if (sorted_fout.is_open()){
        for (auto el: sorted_nums){
            sorted_fout << el << endl;
        }
    }
    sorted_fout.close();
    
}

int main(){ // one, two, N_six, N_twenty, N = three, four, five
    five_twenty();
    return 0;
}