#include <bits/stdc++.h>
using namespace std;
int main() {
    int cantidadacusados;
    cin >> cantidadacusados;
    vector<int> acusaciones;
    int temp;
    for(int i = 0; i < cantidadacusados;i++){
        cin >> temp;
        temp = temp -1;
        acusaciones.push_back(temp);
    }
    bool acusado = false;
    for(int j = 0; j < cantidadacusados; j++){
        vector<bool> fuiacusado(cantidadacusados,false);
        fuiacusado[j] = true;
        int punt = acusaciones[j];
        while(!fuiacusado[punt]){
            fuiacusado[punt] = true;
            punt = acusaciones[punt];
        }
        if(j == cantidadacusados - 1){
            cout <<punt + 1 << endl;
            continue;
        }
        cout <<punt + 1 << ' ';
    }

    return 0;
}
