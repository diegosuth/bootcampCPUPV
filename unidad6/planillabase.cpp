#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string base = "";
    int contador = 0;
    string lineaprevia = "11";
    char previo = '1';
    int contadoralt = 0;
    for(int i = 0; i < n-2; i++){
        for(char c: lineaprevia){
            contadoralt++;
            contador++;
            if(c != previo || contadoralt == lineaprevia.length()-1){
                for(int j = 0; j <= contador; j++){
                    base += to_string(contador) + previo;
                }
                previo = c;
                contador = 0;
                continue;
            }
            previo = c;
        }
        contadoralt = 0;
        lineaprevia = base;
        base = "";
    }
    cout << lineaprevia;
return 0;    
}
