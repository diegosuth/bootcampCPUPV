#include <bits/stdc++.h>
using namespace std;

int main(){
    int variedades;
    string cantidades;
    cin >> variedades;
    int temp;
    int arrayhelados[variedades];
    memset(arrayhelados,0,sizeof(arrayhelados));
    cin.ignore();
    getline(cin,cantidades);
    istringstream iss(cantidades);
    for(int i = 0; i < variedades ; i++){
        iss >> arrayhelados[i];
        }
    getline(cin,cantidades);
    istringstream jss(cantidades);
    for (int j = 0; j < variedades; j++){
        jss >> temp;
        arrayhelados[j] = arrayhelados[j] + temp;
    }
    for (int h : arrayhelados){ // h toma el valor del valor dentro del array en la respectiva posicion de la iteracion
        cout << h << " ";
    }
return 0;    
}
