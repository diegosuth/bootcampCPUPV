#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<char> fila0;
    queue<char> fila1;
    queue<char> fila2;
    int longitudfilas;
    cin >> longitudfilas; 
    for(int j = 0; j < longitudfilas; j++){
            char temp;
            cin >> temp;
            fila0.push(temp);
        }
    for(int j = 0; j < longitudfilas; j++){
            char temp;
            cin >> temp;
            fila1.push(temp);
        }
    for(int j = 0; j < longitudfilas; j++){
            char temp;
            cin >> temp;
            fila2.push(temp);
        }
    cin.ignore();
    string linea;
    string accion;
    while(getline(cin,linea)){
        istringstream iss(linea);
        iss >> accion;
        int identificadorcoladesde;
        int identificadorcolahacia;
        char id;
        if(accion == "MOVER"){
            iss >> identificadorcoladesde >> identificadorcolahacia;
            if(identificadorcoladesde == 0){
                if(!fila0.empty()){
                    if(identificadorcolahacia == 1){
                        fila1.push(fila0.front());
                        fila0.pop();
                    }
                    else{//fila2
                        fila2.push(fila0.front());
                        fila0.pop();
                }
            }
            
        }
            else if(identificadorcoladesde == 1){
                if(!fila1.empty()){
                    if(identificadorcolahacia == 0){
                        fila0.push(fila1.front());
                        fila1.pop();
                    }
                else{//fila2
                    fila2.push(fila1.front());
                    fila1.pop();
                }
            }
        }
            else{//cola2
                if(!fila2.empty()){
                    if(identificadorcolahacia == 0){
                        fila0.push(fila2.front());
                        fila2.pop();
                    }
                    else{//fila1
                        fila1.push(fila2.front());
                        fila2.pop();
                    }
                }
            }
        }
        else if(accion == "ATENDER"){
            iss >> identificadorcoladesde; 
            if(identificadorcoladesde == 0){
                if(!fila0.empty()){
                    fila0.pop();
                }
            }
            else if(identificadorcoladesde == 1){
                if(!fila1.empty()){
                    fila1.pop();
                }
                
            }
            else{//cola2
                if(!fila2.empty()){
                    fila2.pop();
                }
            }
        }
        else{//agregar
            iss >> id >> identificadorcolahacia;
            if(identificadorcolahacia == 0){
                fila0.push(id);
            }
            else if(identificadorcolahacia == 1){
                fila1.push(id);
            }
            else{//fila2
                fila2.push(id);
            }
        }

    }
    if(fila0.empty()){
        cout << "NO HAY NADIE" << endl;
    }
    else{
        while(!fila0.empty()){
        if(fila0.size() == 1){
            cout << fila0.front() << endl;
            fila0.pop();
            break;
        }
        cout << fila0.front() << ' ';
        fila0.pop();
        }
    }
    if(fila1.empty()){
        cout << "NO HAY NADIE" << endl;
    }
    else{
        while(!fila1.empty()){
            if(fila1.size() == 1){
                cout << fila1.front() << endl;
                fila1.pop();
                break;
                }   
            cout << fila1.front() << ' ';
            fila1.pop();
            }
        }
    if(fila2.empty()){
        cout << "NO HAY NADIE" << endl;
    }
    else{
    while(!fila2.empty()){
        if(fila2.size() == 1){
            cout << fila2.front() << endl;
            fila2.pop();
            break;
        }
        cout << fila2.front() << ' ';
        fila2.pop();
    }
}
    return 0;
}
