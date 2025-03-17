#include <iostream>
#include <iomanip>

using namespace std;


class Stack{
    string name;
    int maxSize;
    int cntItems = 0;
    int* data = nullptr;

    public:
        Stack(string name, int maxSize){
            this->name = name;
            this->maxSize = maxSize;
            data = new int[maxSize];
        }

        ~Stack(){
            delete[] data;
        }

        int getCntItems(){
            return cntItems;
        }

        string getName(){
            return name;
        }

        bool push(int el){
            if (cntItems < maxSize){
                data[cntItems] = el;
                cntItems += 1;
                return true;
            }
            else{
                return false;
            }
        }

        bool pop(int* val){ // значение записать в val
            if (cntItems > 0){
                *val = data[cntItems-1];
                cntItems -= 1;
                return true;
            }
            else{
                return false;
            }
        }
};


int main(){
    // Stack s = Stack("test", 3);
    // if(s.push(420)) cout << 1 << endl;
    // int val = 0;
    // if(s.pop(&val)) cout << 2 << endl;
    // cout << val;

    cout.width(15);
    cout.setf(ios::left);

    string name1; int size1;
    cout << "s1 name and size: ";
    cin >> name1 >> size1;
    Stack s1 = Stack(name1, size1);
    cout << s1.getName() << size1 << endl;

    int input;
    cout << "s1 el: ";
    while (cin >> input) {
        if (input == 0) {
            break;
        }
        s1.push(input);
    }

    string name2; int size2;
    cout << "s2 name and size: ";
    cin >> name2 >> size2;
    Stack s2 = Stack(name2, size2);
    cout << s2.getName() << size2 << endl;

    cout << "s2 el: ";
    while (cin >> input) {
        if (input == 0) {
            break;
        }
        s2.push(input);
    }
    
    cout << s1.getName() << s2.getName() << endl;
    while (s1.getCntItems() > 0 && s2.getCntItems() > 0){
        cout << 1;
        int val1, val2;
        s1.pop(&val1);
        s2.pop(&val2);
        cout << val1 << val2 <<endl;
   }


    return 0;
}