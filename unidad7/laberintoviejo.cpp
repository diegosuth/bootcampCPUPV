#include <bits/stdc++.h>
using namespace std;
int main() {
    int cantidadinstrucciones;
    cin >> cantidadinstrucciones;
    stack<int> instruccionesfinales;
    for(int i = 0; i < cantidadinstrucciones; i++){
        char temp;
        cin >> temp;
        if(instruccionesfinales.empty()){
            instruccionesfinales.push(temp);
        }
        else{
            if(temp == 'F'){
                if(instruccionesfinales.top() == 'B'){
                    instruccionesfinales.pop();
                    continue;
                }
                instruccionesfinales.push(temp);
            }
            else if(temp == 'R'){
                if(instruccionesfinales.top() == 'L'){
                    instruccionesfinales.pop();
                    continue;
                }
                instruccionesfinales.push(temp);
            }
            else if(temp == 'B'){
                if(instruccionesfinales.top() == 'F'){
                    instruccionesfinales.pop();
                    continue;
                }
                instruccionesfinales.push(temp);
            }
            else if(temp == 'L'){
                if(instruccionesfinales.top() == 'R'){
                    instruccionesfinales.pop();
                    continue;
                }
                instruccionesfinales.push(temp);
            }
        }
    }
    vector<char> caminofinal;
    while(!instruccionesfinales.empty()){
        caminofinal.push_back(instruccionesfinales.top());
        instruccionesfinales.pop();
    }
    for(int d = caminofinal.size()-1; d >=0; d--){
        if(d == 0){
            cout << caminofinal[d] << endl;
        }
        else{
            cout << caminofinal[d] << ' ';
        }

    }
return 0;
}
