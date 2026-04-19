#include <bits/stdc++.h>
using namespace std;

int main(){
    int fila;
    int columna;
    bool original = true;
    string cuadro;
    cin >> fila >> columna;
    char pintura[fila][columna];
    cin.ignore();
    for (int i = 0; i < fila ;i++){
        getline(cin, cuadro);
        istringstream iss(cuadro);
        for (int j = 0; j < columna;j++){
            iss >> pintura[i][j];
        }
    }
    for (int k = 0;k < fila; k++){
        if (k == fila - 1){
            continue;
        }
        for (int l = 0; l < columna; l++){
            if (l == columna - 1){
                continue;
            }
            if (pintura[k][l] == pintura[k+1][l] && pintura[k][l] == pintura[k][l+1] && pintura[k][l] == pintura[k+1][l+1]){
                original = false;
            }
        }
    }
    if(original){
        cout << "ORIGINAL";
    }
    else{
        cout << "NO ORIGINAL";
    }
return 0;    
}
