#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
bool bfs(int startNode, int edges, const vector<vector<int>>& adj, int V){//para revisar si todos estan conectados
    vector<bool> nodevisited(V, false);
    queue<int> nodeproc;//queue para procesar nodos
    nodevisited[startNode] = true;
    nodeproc.push(startNode);
    while(!nodeproc.empty()){
        int currentnode = nodeproc.front();
        nodeproc.pop();
        for(int neighbour: adj[currentnode]){//reviso todos los nodos conectados a current
            if(!nodevisited[neighbour]){
                nodevisited[neighbour] = true;
                nodeproc.push(neighbour);//guardo el encontrado para explorar sus vecinos luego
            }
        }
    }
    for(bool b : nodevisited){//descarto si alguno esta desconectado
        if(!b){
            return false;
        }
    }
    return true;
}
bool isValid(int r, int c,int vertex,int edges) {
    return r >= 0 && r < vertex  && c >= 0 && c < edges;
}

// DFS que retorna true si encontramos el camino
bool DFS(int verticestots, int edges, vector<pii>& calles) {
        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int verticestots;
    int edges;
    int start;
    cin >> verticestots >> edges >> start;
    vector<vector<int>> conexiones(verticestots);
    vector<pii> calles(edges);
    vector<vector<bool>> visitedaristas(verticestots);
    start--;
    int a;
    int b;
    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        a--;
        b--;
        calles[i] = {a,b};
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
    if(!evendegree || !bfs(0,edges,conexiones,verticestots)){
        cout << -1 << endl;
    }
    else{
        
    }
    return 0;    
}