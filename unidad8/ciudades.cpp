#include <bits/stdc++.h>
using namespace std;
bool bfs(int startNode, int obj, const vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    vector<int> parent(V,-1); //guarda el camino final optimo
    queue<int> proc;
    visited[startNode] = true;
    proc.push(startNode);
    while(!proc.empty()){
        int current = proc.front();
        proc.pop();
        for(int neighbour: adj[current]){//reviso todos los nodos conectados a current
            if(!visited[neighbour]){
                visited[neighbour] = true;
                proc.push(neighbour);//guardo el encontrado para explorar sus vecinos luego
                parent[neighbour] = current;
            }
        }
    }
    for(bool b : visited){//descarto si alguno esta desconectado
        if(!b){
            return false;
        }
    }
    vector<int>caminobest;
    int lastone = obj;
    while(lastone != -1){//si llego a -1 es el inicio, voy de final -> inicio
        caminobest.push_back(lastone);
        lastone = parent[lastone];//voy y reviso quien es el padre del ultimo, y luego 
        //el padre de ese, y asi hasta llegar al inicio
    }
    for(int d : caminobest){
        cout << d  + 1<< endl;
    }
    return true;
}
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
    if(!evendegree || !bfs(0,verticestots-1,conexiones,verticestots)){
        cout << -1 << endl;
    }
    else{//agregar logica para revisar si estan todos conectados

    }
    return 0;    
}