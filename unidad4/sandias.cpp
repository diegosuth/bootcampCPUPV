#include <bits/stdc++.h>
using namespace std;

int main(){
    int filacampo;
    int columnacampo;
    string sandias;
    int maxsandias = 0;
    int sumatoriasandiashorizontal = 0;
    int sumatoriasandiasvertical = 0;
    cin >> filacampo >> columnacampo;
    cin.ignore();
    int campo[filacampo][columnacampo];
    for (int i = 0; i < filacampo;i++){
        getline(cin,sandias);
        istringstream iss(sandias);
        for(int j = 0; j < columnacampo; j++){
            iss >> campo[i][j];
        }
    }
    for(int k = 0; k < filacampo; k++){ //calculo filas
        for(int m = 0; m < columnacampo; m++){
            sumatoriasandiashorizontal += campo[k][m];
            if(sumatoriasandiashorizontal >= maxsandias){
                maxsandias = sumatoriasandiashorizontal;
            }
        }
        sumatoriasandiashorizontal = 0;
    }
    for(int l = 0; l < columnacampo; l++){ //calculo columnas
        for(int o = 0; o < filacampo; o++){
            sumatoriasandiasvertical += campo[o][l];
            if (sumatoriasandiasvertical >= maxsandias) {
                maxsandias = sumatoriasandiasvertical;
            }
        }
        sumatoriasandiasvertical = 0;
    }
    cout << maxsandias;

return 0;    
}

