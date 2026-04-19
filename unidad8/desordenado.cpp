#include <bits/stdc++.h>
using namespace std;

int main(){
int verticestots;
int edges;
cin >> verticestots >> edges;
int a;
int b;
vector<vector<bool>> combinaciones(verticestots + 1,vector<bool>(verticestots + 1,false));
for(int i = 0; i < edges; i++){
    cin >> a >> b;
    combinaciones[a][b] = true;
    combinaciones[b][a] = true;
}
long long combinacionestotales = (verticestots * (verticestots - 1)) / 2;
cout << combinacionestotales - edges << endl;
if(combinacionestotales == edges){

}
else{
    for(int s = 1; s <= verticestots; s++){
        for(int d = s+1; d <= verticestots; d++){
            if((combinaciones[d][s]) || (combinaciones[s][d])){
                continue;
            }
            else{
                cout << s << ' ' << d << endl;
                combinaciones[s][d] = true;
                combinaciones[d][s] = true;
            }
        }
    }
}

return 0;    
}
