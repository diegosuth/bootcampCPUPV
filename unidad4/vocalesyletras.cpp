#include <bits/stdc++.h>
using namespace std;

int main(){
string frase;
int casos;
int contavocales = 0;
int contaletras = 0;
cin >> casos;
cin.ignore();
for (int i = 0 ;i<casos;i++){
        for (char c : frase){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                contavocales += 1;
                contaletras += 1;
            }
            else if(c == ' '){
                continue;
            }
            
            else{
                contaletras += 1;
            }
        }
    cout << contavocales << " " << contaletras << endl;
    contavocales = 0;
    contaletras = 0;
    }
return 0; 
}




