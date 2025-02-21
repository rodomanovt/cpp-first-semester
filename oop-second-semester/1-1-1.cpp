#include <iostream>

int main(){
    int x;
    std::cin >> x;
    if (x % 2 == 0){
        std::cout << "even";
    }
    else{
        std::cout << "uneven";
    }
    return 0;
}