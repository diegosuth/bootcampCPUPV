#include <bits/stdc++.h>
using namespace std;

int main(){
    int sizetostada;
    string vacio;
    cin >> sizetostada;
    char tostada[sizetostada][sizetostada];
    char tostadacaida[sizetostada][sizetostada];
    string mermelada;
    bool asalvo = true;
    bool nollevamermelada = true;
    string postcaida;
    cin.ignore();
    getline(cin, vacio);
    for (int i = 0; i < sizetostada; i++){
        getline(cin,mermelada);
        istringstream iss(mermelada);
        for(int j = 0; j < sizetostada; j++){

            iss >> tostada[i][j];
            if (tostada[i][j] == '#'){
                nollevamermelada = false;
            }
        }
    }
    getline(cin, vacio);
    for (int k = 0; k < sizetostada; k++){
        getline(cin,postcaida);
        istringstream jss(postcaida);
        for(int m = 0; m < sizetostada; m++){
            jss >> tostadacaida[k][m];
            if (tostadacaida[k][m] == ' '){
                continue;
            }
            if (tostadacaida[k][m] != tostada[k][m]){
                asalvo = false;
            }
        }
    
}
    if(nollevamermelada){
        cout << "NO LLEVABA MERMELADA";
    }
    else if (asalvo){
        cout << "HA HABIDO SUERTE";
    }
    else{
        cout << "TRAGEDIA";
    }
return 0;    
}
