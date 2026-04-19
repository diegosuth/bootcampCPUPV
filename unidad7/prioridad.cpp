#include <bits/stdc++.h>
using namespace std;
int main() {
    long long cantidadtareas;
    cin >> cantidadtareas;
    priority_queue<pair<long long,long long>> prioridades;
    string linea;
    cin.ignore();
    for(long long i = 0; i < cantidadtareas; i++){
        getline(cin,linea);
        istringstream iss(linea);
        char instruccion;
        iss >> instruccion;
        if(instruccion == '+'){
            long long prioridad;
            long long id;
            iss >> prioridad >> id;
            prioridades.push({prioridad,id});
        }
        else if(instruccion == '-'){
            long long prioridad;
            long long id;
            vector<pair<long long, long long>> helper;
            iss >> id;
            while(!prioridades.empty()){
                if(prioridades.top().second == id){
                    prioridades.pop();
                    break;
                }
                helper.push_back({prioridades.top()});
                prioridades.pop();
            }
            for(auto const& [prioridad,id] : helper){
                prioridades.push({prioridad,id});
            }
            cout << id << endl;
        }
        else if(instruccion == '!'){
            cout << prioridades.top().second << endl;
            prioridades.pop();
        }
    }


    return 0;
}
