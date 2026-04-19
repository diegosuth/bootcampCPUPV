#include <bits/stdc++.h>
using namespace std;
void bfs(int startNode, int obj, const vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    vector<int> dist(V,0);//cuenta la cantidad de pasos hasta el nodo n
    vector<int> parent(V,-1); //guarda el camino final optimo
    queue<int> proc;
    visited[startNode] = true;
    proc.push(startNode);

    while(!proc.empty()){
        int current = proc.front();
        proc.pop();
        if(current == obj){
            break;
        }
        for(int neighbour: adj[current]){//reviso todos los nodos conectados a current
            if(!visited[neighbour]){
                visited[neighbour] = true;
                proc.push(neighbour);//guardo el encontrado para explorar sus vecinos luego
                dist[neighbour] = dist[current] + 1;
                parent[neighbour] = current;
            }
        }
    }
    cout << dist[obj] << endl;
    vector<int>caminobest;
    int lastone = obj;
    while(lastone != -1){//si llego a -1 es el inicio, voy de final -> inicio
        caminobest.push_back(lastone);
        lastone = parent[lastone];//voy y reviso quien es el padre del ultimo, y luego 
        //el padre de ese, y asi hasta llegar al inicio
    }
    reverse(caminobest.begin(),caminobest.end());
    int counter = caminobest.size();
    for(int d : caminobest){
        if(counter == 1){
            cout << d + 1 << endl;
            continue;
        }
        cout << d  + 1<< ' ';
        counter--;
    }
}
int main() {
    long verticestots;
    long conexionestots;
    long casa;
    long universidad;
    cin >> verticestots >> conexionestots >> casa >> universidad;
    vector<vector<int>> conexiones(verticestots);
    long a;
    long b;
    casa--;
    universidad--;
    for(int i = 0; i < conexionestots; i++){
        cin >> a >> b;
        a--;
        b--;
        conexiones[a].push_back(b);
        conexiones[b].push_back(a);
    }
    bfs(casa,universidad,conexiones,verticestots);
    return 0;
}
