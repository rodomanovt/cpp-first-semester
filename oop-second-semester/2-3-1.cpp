#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;



class Cl{
	short priv;
	
	public:
		int pub;
		char m[4];
		
		void setPriv(short val){
            this->priv = val;
        }
        
        short getPriv(){
            return priv;
        }
};


union Un{
	int pub;
	char m[4];
		
	void setPriv(short val){
        this->priv = val;
    }
    
    short getPriv(){
        return priv;
    }
	
	private:
		short priv;
};


void printArray(char* arr){
	int i = 0;
	while (i < 4){
		cout << arr[i];
		i += 1;
	}
	cout << endl;


	// for (int i = 0; i < 4; i++){
	// 	cout << arr[i];
	// }
	// cout << endl;
}

	
bool acceptable(int hexValue){
	if (hexValue == 0){
		return false;
	}
    while (hexValue > 0){
        unsigned int byte = hexValue & 0xFF;
        hexValue >>= 8;
        if (!((byte >= 'A' && byte <= 'Z') || (byte >= 'a' && byte <= 'z'))){
            return false;
        }
    }
    return true;
}


int main()
{
	Un obj_un;
	Cl obj_cl;
	char ch[4];
	cin >> ch;
	int i = 0;
	while (i < 4){
		obj_un.m[i] = ch[i];
		obj_cl.m[i] = ch[i];
		i += 1;
	}
	// for (int i = 0; i < 4; ++i) {
	// 	obj_un.m[i] = ch[i];
	// 	obj_cl.m[i] = ch[i];
	// }

	while (true){
		int valPub = 0;
		short valPriv = 0;
		cin >> std::hex >> valPub;
		if (cin.peek() != '\n'){
			cin >> std::hex >> valPriv;
		}
		while (!acceptable(valPub) || !acceptable(valPriv)){
			if (valPub == 0) return 0;
			if (!acceptable(valPub)){
				cout << "Data of the int type is incorrect: " << std::hex << valPub << endl;
			}
			else {
				cout << "Data of the short type is incorrect: " << std::hex << valPriv << endl;
			}
			cin >> std::hex >> valPub;
			if (cin.peek() != '\n'){
				cin >> std::hex >> valPriv;
			}
		}

		obj_un.pub = valPub;
		obj_cl.pub = valPub;
		obj_un.setPriv(valPriv);
		obj_cl.setPriv(valPriv);

		printArray(obj_un.m);
		printArray(obj_cl.m);
	}
}
