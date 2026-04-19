#include <bits/stdc++.h>
using namespace std;
struct candidato{
    int n;
    int m;
    int valor;
};
int main(){
    int casos;
    int filas;
    int columnas;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        cin >> filas >> columnas;
        int matriz[filas][columnas];
        for(int f = 0; f < filas; f++){
            for(int c = 0; c < columnas; c++){
                cin >> matriz[f][c];
            }
        }
        candidato menoresfila[filas];
        candidato mayorescolumna[columnas];
        for(int m = 0; m < filas;m++){
            int menorfila = 32769;
            for(int n = 0; n < columnas;n++){
                if(matriz[m][n] < menorfila){
                    menorfila = matriz[m][n];
                    menoresfila[m].m = m;
                    menoresfila[m].n = n;
                    menoresfila[m].valor = matriz[m][n];
                }
            }

        }
        for(int d = 0; d < columnas; d++){
            int mayorcolumna = 0;
            for(int b = 0; b < filas; b++){
                if(matriz[b][d] > mayorcolumna){
                    mayorcolumna = matriz[b][d];
                    mayorescolumna[d].m = b;
                    mayorescolumna[d].n = d;
                    mayorescolumna[d].valor = matriz[b][d];
                }
            }
        }
        pair <int , int> puntosilla;
        bool esverdadero = false;
        for(candidato f : menoresfila){
            for(candidato c : mayorescolumna){
                if(f.m == c.m && f.n == c.n){
                    esverdadero = true;
                    puntosilla.first = f.m;
                    puntosilla.second = f.n;
                    break;
                }
            }
            if (esverdadero){
                break;
            }
        }
        if(esverdadero){
            cout << puntosilla.first << ' ' << puntosilla.second << endl;
        }
        else{
            cout << -1 << ' ' << -1 << endl;
        }
    }
return 0;    
}
