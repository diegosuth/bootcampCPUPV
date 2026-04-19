#include <bits/stdc++.h>
using namespace std;

int main(){
    int cantidadtotal;
    cin >> cantidadtotal;
    int cantidadproblemas;
    int penalizacion;
    pair <int, int> lista[cantidadtotal];
    for(int i = 0; i < cantidadtotal;i++){
        cin >> cantidadproblemas >> penalizacion;
        lista[i] = make_pair(cantidadproblemas,penalizacion);
    }
    sort(lista,lista + cantidadtotal,[](auto &a,auto &b){
        if(a.first != b.first){//if the first two elements are equal
        return a.first > b.first;//main logic
        }
        return a.second < b.second; //tiebreaker
    });
    for(auto const& [cantidadproblemas,penalizacion]:lista){
        cout << cantidadproblemas << ' ' << penalizacion << endl;
    }
return 0;    
}
