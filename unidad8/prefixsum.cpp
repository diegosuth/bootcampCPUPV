#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cantidadrouters;
    long long latenciaenlace;
    long long queries;
    cin >> cantidadrouters >> latenciaenlace >> queries;
    vector<long long> routers;
    vector<long long>prefixsum;
    long long sumatoria = 0;
    for(int i = 0; i < cantidadrouters; i++){
        long long temp;
        cin >> temp;
        sumatoria += temp;
        routers.push_back(temp);
        sumatoria+=latenciaenlace;
        prefixsum.push_back(sumatoria);
    }
    for(int j = 0; j < queries; j++){
        long long routera;
        long long routerb;
        long long resultado = 0;
        cin >> routera >> routerb;
        routera--;
        routerb--;
        if(routera == routerb){
            cout << 0 << endl;
        }
        else{
            if(routera != 0){
                resultado = prefixsum[routerb] + prefixsum[routerb-1] - prefixsum[routera-1] - prefixsum[routera];
            cout << resultado << endl;
            }
            else{
                resultado = prefixsum[routerb] + prefixsum[routerb-1] - prefixsum[routera];
                cout << resultado << endl;
            }
        
    }
}
for(long long l: prefixsum){
    cout << l << endl;
}

    
return 0;    
}