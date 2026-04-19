#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int filas;
    int contadorbomba = 0;
    int columnas;
    string elementos;
    cin >> filas >> columnas;
    char tablero[filas][columnas];
    cin.ignore();
    for (int i = 0; i < filas;i++){ //recoleccion matriz
        getline(cin,elementos);
        istringstream iss(elementos);
        for(int j = 0; j < columnas; j++){
            iss >> tablero[i][j];
            if(tablero[i][j] == '*'){
                tablero[i][j] = 'F';
            }
        }
    }
    for (int m = 0; m < filas; m++){
        for (int n = 0; n < columnas; n++){
            contadorbomba = 0;
            if (tablero[m][n] == 'F'){
                continue;
            }
            if (columnas == 1){
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if (contadorbomba == 0){
                tablero[m][n] = ' ';
                break;
            }
            tablero[m][n] = contadorbomba + '0';
                break;
            }
            else if (m == 0 && n == 0){ // esquina superior izquierda
                if (tablero[m][n+1] == 'F'){ //derecha
                    contadorbomba += 1;
                }
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }
                if (tablero[m+1][n+1] == 'F'){//diagonal hacia inferior derecha
                    contadorbomba += 1;
                }
            } 
            else if (m == (filas-1) && n == 0) { // esquina inferior izquierda
                if (tablero[m][n+1] == 'F'){ //derecha
                    contadorbomba += 1;
                }
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if (tablero[m-1][n+1] == 'F'){ //diagonal hacia superior derecha
                    contadorbomba += 1;
                }
            }
            else if (m == 0 && n == (columnas - 1)){ // esquina superior derecha
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }
                if (tablero[m][n-1] == 'F'){ //izquierda
                    contadorbomba +=1;
                }
                if (tablero[m+1][n-1] == 'F'){ //diagonal hacia inferior izquierda
                    contadorbomba +=1;
                }
            } 
            else if(m == (filas-1) && n==columnas-1){ // esquina inferior derecha
                if (tablero[m][n-1] == 'F'){ //izquierda
                    contadorbomba +=1;
                }
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if(tablero[m-1][n-1] == 'F'){//diagonal hacia superior izquierda
                    contadorbomba += 1;
                } 
            }
            else if(n == 0){ //checkeo pared izquierda
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if (tablero[m-1][n+1] == 'F'){ //diagonal hacia superior derecha
                    contadorbomba += 1;
                }
                if (tablero[m][n+1] == 'F'){ //derecha
                    contadorbomba += 1;
                }
                if (tablero[m+1][n+1] == 'F'){//diagonal hacia inferior derecha
                    contadorbomba += 1;
                }
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }}
            else if(n == (columnas-1)){ //checkeo pared derecha
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if(tablero[m-1][n-1] == 'F'){//diagonal hacia superior izquierda
                    contadorbomba += 1;
                }
                if (tablero[m][n-1] == 'F'){ //izquierda
                    contadorbomba +=1;
                }
                if (tablero[m+1][n-1] == 'F'){ //diagonal hacia inferior izquierda
                    contadorbomba +=1;
                }
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }
            }
            else if(m == 0){ //checkeo pared arriba
                if (tablero[m][n-1] == 'F'){ //izquierda
                    contadorbomba +=1;
                }
                if (tablero[m+1][n-1] == 'F'){ //diagonal hacia inferior izquierda
                    contadorbomba +=1;
                }
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }
                if (tablero[m+1][n+1] == 'F'){//diagonal hacia inferior derecha
                    contadorbomba += 1;
                }
                if (tablero[m][n+1] == 'F'){ //derecha
                    contadorbomba += 1;
                }

            }
            else if(m == filas-1){ //checkeo pared abajo
                if (tablero[m][n-1] == 'F'){ //izquierda
                    contadorbomba +=1;
                }
                if(tablero[m-1][n-1] == 'F'){//diagonal hacia superior izquierda
                    contadorbomba += 1;
                }
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if (tablero[m-1][n+1] == 'F'){ //diagonal hacia superior derecha
                    contadorbomba += 1;
                }
                if (tablero[m][n+1] == 'F'){ //derecha
                    contadorbomba += 1;
                }
            }
            else { //caso normal
                if(tablero[m-1][n] == 'F'){ // arriba
                    contadorbomba += 1;
                }
                if (tablero[m-1][n+1] == 'F'){ //diagonal hacia superior derecha
                    contadorbomba += 1;
                }
                if (tablero[m][n+1] == 'F'){ //derecha
                    contadorbomba += 1;
                }
                if (tablero[m+1][n+1] == 'F'){//diagonal hacia inferior derecha
                    contadorbomba += 1;
                }
                if (tablero[m+1][n] == 'F'){//abajo
                    contadorbomba += 1;
                }
                if (tablero[m+1][n-1] == 'F'){ //diagonal hacia inferior izquierda
                    contadorbomba +=1;
                }
                if (tablero[m][n-1] == 'F'){ //izquierda
                    contadorbomba +=1;
                }
                if(tablero[m-1][n-1] == 'F'){//diagonal hacia superior izquierda
                    contadorbomba += 1;
                }
                if (contadorbomba == 0){
                tablero[m][n] = ' ';
                }
            }
            if (contadorbomba == 0){
                tablero[m][n] = ' ';
                continue;
            }
            tablero[m][n] = contadorbomba + '0';
        }
    }
    for (int k = 0; k < filas;k++){
        for (int l = 0; l<columnas;l++){
            cout << tablero[k][l];
        }
        cout << "\n";
    }
return 0;    
}
