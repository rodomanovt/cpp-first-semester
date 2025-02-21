#include <iostream>
#include <vector>
using namespace std;


void one(){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int n = (c-a)/b;
    cout << n << endl;
}


void two(){
    int m;
    cin >> m;
    int triple = 0;
    int quad = 0;
    while(m % 4 != 0 && m >= 3){
        m -= 3;
        triple += 1;
    }
    if (m % 4 != 0){
        triple = 0;
        quad = 0;
    }
    else{
        quad = m / 4;
    }
    cout << triple << endl;
    cout << quad << endl;
}


void three(){
    int n, m;
    cin >> n;
    cin >> m;
    int cnt = 0;
    for (int a = 1; a <= n; a++){
        for (int b = 1; b <= m; b++){
            // посчитать кол-во возможных расположений левого верхнего угла так, чтобы 
            //прямоугольник a x b не выходил за границы n x m
            cnt += (n-a+1) * (m-b+1);
        }
    }
    cout << cnt << endl;
}


bool isInVector(auto element, vector<auto> arr){
    for (auto el: arr){
        if (el == element){
            return true;
        }
    }
    return false;
}


void four(){
    int n;
    cin >> n;
    vector<int> free_places = {};
    for (int i = 0; i < n; i++){
        int place;
        cin >> place;
        free_places.push_back(place);
    }

    const vector<vector<int>> places = 
                        {{1, 2, 3, 4, 53, 54},
                        {5, 6, 7, 8, 51, 52},
                        {9, 10, 11, 12, 49, 50},
                        {13, 15, 14, 16, 47, 48},
                        {17, 19, 18, 20, 45, 46},
                        {21, 22, 23, 24, 43, 44},
                        {25, 26, 27, 28, 41, 42},
                        {29, 30, 31, 32, 39, 40},
                        {33, 34, 35, 36, 37, 38}};

    vector<int> free_kupe = {}; // массив с номерами свободных купе
    for (int c = 0; c < places.size(); c++){
        bool flag = true;
        for (int i = 0; i < places[0].size(); i++){
            if(!isInVector(places[c][i], free_places)){
                flag = false;
            }
        }
        if (flag){
            free_kupe.push_back(c);
        }
    }
    
    int maxil = 0;
    int len = 1;
    for (int i = 0; i < free_kupe.size(); i++){ // поиск длины самой длинной подпоследовательности идущих подряд чисел
        if (free_kupe[i] - free_kupe[i-1] == 1){
            len += 1;
        }
        else{
            maxil = max(maxil, len);
            len = 1;
        }
    }
    cout << maxil << endl;
}


vector<int> recursive(int longest, int second_longest, int r1, int r2, int remaining_iterations){
    // на первой итерации даны longest, second_longest, равные первому разбитию
    // разбить longest пополам
    // записать расстояния r1, r2; большее из них = second_longest на следующей итерации
    // текущее second_longest = longest на следующей итерации
    
    if (remaining_iterations == 1){
        return vector<int> {r1, r2};
    }
    else{
        if (longest % 2 == 0){
            r1 = (longest - 1) / 2;
            r2 = longest - ((longest - 1) / 2) - 1;
        }
        else{
            r1 = (longest - 1) / 2;
            r2 = (longest - 1) / 2;
        }

        return recursive(second_longest, max(r1, r2), r1, r2, remaining_iterations-1);
    }
}


void five(){
    int n, k;
    cin >> n;
    cin >> k;
    int lplaces, rplaces;
    if (n % 2 == 0){
        lplaces = (n-1) / 2;
        rplaces = n - lplaces - 1;
    }
    else{
        lplaces = (n-1) / 2;
        rplaces = (n-1) / 2;
    }
    vector<int> res = recursive(max(lplaces, rplaces), min(lplaces, rplaces), lplaces, rplaces, k);
    cout << min(res[0], res[1]) << endl << max(res[0], res[1]);
}


int main(){
    five();
    return 0;
}