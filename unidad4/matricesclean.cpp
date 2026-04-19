#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos;
    int filas;
    int columnas;
    float epsilon;
    string fila;
    cin >> casos;
    for (int c = 0; c < casos; c++){
        cin >> filas >> columnas >> epsilon;
        float matriz[filas][columnas];
        cin.ignore();
        for (int i = 0; i < filas; i++ ){
            getline(cin,fila);
            istringstream iss(fila);
            for (int j = 0; j < columnas; j++){
                iss >> matriz[i][j];
            }
        }
        for (int m = 0; m < filas; m++){
            for (int n = 0; n < columnas; n++){
                if(matriz[m][n] <= epsilon){
                    matriz[m][n] = 0;
                }
                cout << setprecision(6) << fixed << matriz[m][n] << ' ';
            }
            cout << "\n";
        }
    }
return 0;    
}
