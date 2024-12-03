#include <iostream>
#include <vector>
using namespace std;


void print_matrix(vector<vector<auto>>& a){
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void print_vector(vector<auto>& a){
    for (auto el: a){
        cout << el << " ";
    }
    cout << endl;
}

//Из урны с N пронумерованными шариками вынимают по одному шарику.
// Подсчитать общее количество ситуаций, когда номер хотя бы одного вынутого
// шарика совпадает с порядковым номером действия "вынимания", например, когда
// шарик № 3 будет вынут 3-им по порядку.

vector<vector<int>> permutations = {};

void generate_permutations(vector<int>& a, int t){
    int n = a.size();
    if (t == n-1){
        permutations.push_back(a);
    }
    else{
        for (int j = t; j < n; j++){
            swap(a[t], a[j]);
            t++;
            generate_permutations(a, t);
            t--;
            swap(a[t], a[j]);
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> massive = {};
    for (int i = 1; i <= n; i++){
        massive.push_back(i);
    }
    generate_permutations(massive, 0);
    
    int cnt = 0;
    for (vector<int> p: permutations){
        for (int i = 0; i < p.size(); i++){
            if (p[i] == i+1){
                cnt += 1;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}