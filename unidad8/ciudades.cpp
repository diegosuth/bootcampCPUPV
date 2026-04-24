#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
bool bfs(int startNode, int edges, const vector<vector<pii>>& adj, int V){//para revisar si todos estan conectados
    vector<bool> nodevisited(V, false);
    queue<int> nodeproc;//queue para procesar nodos
    nodevisited[startNode] = true;
    nodeproc.push(startNode);
    while(!nodeproc.empty()){
        int currentnode = nodeproc.front();
        nodeproc.pop();
        for(auto const& neighbour: adj[currentnode]){//reviso todos los nodos conectados a current
            if(!nodevisited[neighbour.first]){
                nodevisited[neighbour.first] = true;
                nodeproc.push(neighbour.first);//guardo el encontrado para explorar sus vecinos luego
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

// DFS que retorna true si encontramos el camino
void DFS(int inicio,vector<vector<pii>>& conexiones, vector<bool>& visited, vector<int>& caminofinal) {
        for(auto const& neighbour : conexiones[inicio]){
            if(visited[neighbour.second]){
                continue;
            }
            visited[neighbour.second] = true;
            DFS(neighbour.first,conexiones,visited,caminofinal);
        }
        caminofinal.push_back(inicio);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int verticestots;
    int edges;
    int start;
    cin >> verticestots >> edges >> start;
    vector<vector<pii>> conexiones(verticestots);
    vector<int> caminofinal;
    vector<bool> visited(edges,false);
    start--;
    int a;
    int b;
    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        a--;
        b--;
        conexiones[a].push_back({b,i});
        conexiones[b].push_back({a,i});
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
        DFS(start,conexiones,visited,caminofinal);
        for(int d : caminofinal){
            cout << d + 1 << endl;
        }
    }
    return 0;    
}