#include <bits/stdc++.h>
using namespace std;

int main(){
    int largolista;
    int calidad;
    string tipo;
    cin >> largolista;
    pair <int, string> lista[largolista];
    for(int i = 0; i < largolista; i++){
        cin >> calidad >> tipo;
        lista[i] = make_pair(calidad,tipo);
    }
    sort(lista,lista + largolista);
    for (auto const& [calidad,tipo] : lista){
        cout << calidad << ' ' << tipo << endl;
    }
return 0;    
}
