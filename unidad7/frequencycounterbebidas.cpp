#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<int,int> contadorbebidas;
    int ventastotales;
    cin >> ventastotales;
    for(int i = 0; i < ventastotales; i++){
        int temp;
        cin >> temp;
        contadorbebidas[temp]++;
    }
    int mayoresbebidas = 0;
    int ganador = 0;
    for(auto const& [bebida,freq] : contadorbebidas){
        if(freq > mayoresbebidas){
            ganador = bebida;
            mayoresbebidas = freq;
        }
        else if(freq == mayoresbebidas){
            if(bebida < ganador){
                ganador = bebida;
                mayoresbebidas = freq;
            }
        }
    }
    cout << ganador << endl;
    return 0;
}
