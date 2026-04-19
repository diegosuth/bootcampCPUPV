#include <bits/stdc++.h>
using namespace std;
int main() {
    int acciones;
    cin >> acciones;
    stack<string> libros;
    string accion;
    string libro;
    string instruccion;
    cin.ignore();
    for(int j = 0; j < acciones; j++){
        getline(cin,accion);
        istringstream iss(accion);
        iss >> instruccion;
        if(instruccion == "Depositan"){
            iss >> ws;
            getline(iss,libro);
            libros.push(libro);
        }
        else if(instruccion == "Retiran"){
            if(libros.empty()){
                continue;
            }
            libros.pop();
        }
    }
    if(libros.empty()){
        cout << "No quedan libros" << endl;
    }
    else{
        while(!libros.empty()){
            cout << libros.top() << endl;
            libros.pop();
        }
    }
    return 0;
}
