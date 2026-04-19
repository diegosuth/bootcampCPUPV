#include <bits/stdc++.h>
using namespace std;
int main(){
    int numero;
    cin >> numero;
    for(int h = numero - 1; h > 0; h--){
        for(int g = h; g < numero; g++){
            cout << '#';
        }
        cout << endl;
    }
    for(int i = 0; i < numero; i++){
        for(int j = i; j < numero; j++){
            cout << '#';
        }
        cout << endl;
    }
return 0;    
}
