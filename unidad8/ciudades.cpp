#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int verticestots;
    int edges;
    int start;
    cin >> verticestots >> edges >> start;
    vector<vector<int>> conexiones(verticestots);
    start--;
    int a;
    int b;
    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        a--;
        b--;
        conexiones[a].push_back(b);
        conexiones[b].push_back(a);
    }
    bool evendegree = true;
    for(int v = 0; v < verticestots;v++){
        if(conexiones[v].size() % 2 != 0){
            evendegree = false;
            break;
        }
    }
    if(!evendegree){
        cout << -1 << endl;
    }
    else{//agregar logica para revisar si estan todos conectados

    }
    return 0;    
}