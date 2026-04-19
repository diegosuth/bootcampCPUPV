#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos;
    string palabra;
    int quantasteriscos = 0;
    char letra;
    cin >> casos;
    cin.ignore();
    for (int i = 0; i < casos; i++){
        getline(cin,palabra);
        for (int m = 0; m < palabra.length();m++){ //contador asteriscos finales
            if (palabra[m] ==  ' '){
                quantasteriscos += 4;
                continue;
            }
            if (m == 0){
                quantasteriscos += 6;
                continue;
            }
            if (palabra[m+1] == ' '){
                quantasteriscos += 2;
                continue;
            }
            quantasteriscos += 4;
        }
        for (int j = 0; j < quantasteriscos - 1;j++){ // impresion primera fila asteriscos
            cout << '*';
        }
        cout << endl;
        for (int k = 0; k < palabra.length() - 1;k++){ // impresion linea principal
            if (k == 0){
                cout << "* " << palabra[k] << " * ";
                continue;
            }
            if (palabra[k] == ' '){
                cout << "*** ";
                continue;
            }
            if (palabra[k+1] == ' '){
                cout << palabra[k] << ' ';
                continue;
            }
            cout << palabra[k] << " * ";
        }
        cout << palabra[palabra.length() - 1] << " *";
        cout << endl;
        for (int l = 0; l < quantasteriscos - 1; l++){ // impresion ultima linea
            cout << '*';
        }
        cout << endl;
        quantasteriscos = 0;
    }
return 0;    
}
