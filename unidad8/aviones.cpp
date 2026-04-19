#include <bits/stdc++.h>
using namespace std;
bool bfs(int startNode, int obj, const vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    queue<int> proc;
    visited[startNode] = true;
    proc.push(startNode);
    while(!proc.empty()){
        int current = proc.front();
        proc.pop();
        if(current == obj){
            return false;
        }
        for(int neighbour: adj[current]){//reviso todos los nodos conectados a current
            if(!visited[neighbour]){
                visited[neighbour] = true;
                proc.push(neighbour);//guardo el encontrado para explorar sus vecinos luego
            }
        }
    }
    return true;
}
int main() {
    int vertices;
    cin >> vertices;
    cin.ignore();
    string linea;
    vector<vector<int>> conexiones(vertices);
    while(true){
        getline(cin,linea);
        istringstream iss(linea);
        char operacion;
        int a;
        int b;
        iss >> operacion >> a >> b;
        a--;
        b--;
        if(bfs(a,b,conexiones,vertices)){
            cout << "SI" << endl;
        }
        else{
            cout << "NO" <<endl;
            break;
        }
        conexiones[a].push_back(b);
        conexiones[b].push_back(a);
    }
    return 0;
}
