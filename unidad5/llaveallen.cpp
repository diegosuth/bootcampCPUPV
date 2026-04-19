#include <bits/stdc++.h>
using namespace std;
int restamenor(int n,int h,int comparador){
    int menor = abs(n - h);
    if (menor < comparador) {
        return menor;
    }else{
        return comparador;
    }
}
int main(){
    long long cantidad;
    int menordiferencia;
    cin >> cantidad;
    int opciones[cantidad];
    for(int h = 0; h< cantidad; h++){
        cin >> opciones[h];
    }
    sort(opciones,opciones + cantidad);
    menordiferencia = opciones[cantidad-1];
    for(int k = 0; k < cantidad; k++){
        if ((cantidad - k) >1){
        menordiferencia = restamenor(opciones[cantidad-k-1],opciones[cantidad-k-2],menordiferencia);
    }}
    cout << menordiferencia;
return 0;    
}
