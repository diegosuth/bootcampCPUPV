#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
void dijkstra(int source, const vector<vector<pii>>& adj, vector<int>& dist,vector<int>& parent) {
    int V = adj.size(); // vértices en el grafo
    // Cola de prioridad
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Inicializa distances all vertices as infinite
    dist.assign(V, numeric_limits<int>::max());
    dist[source] = 0; // Distancia al nodo origen es 0
    pq.push({0, source});
    // Procesa la cola de propiedad
    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        int d = pq.top().first;  // Get the distance of the vertex
        pq.pop(); // Remove the vertex from the priority queue

        // Skip processing if the distance is not optimal (stale entry)
        if (d > dist[u]) continue;

        // Traverse all neighbors of the vertex u
        for (const auto& edge : adj[u]) {
            int v = edge.first;    // Neighbor vertex
            int weight = edge.second; // Edge weight

            // Relaxation step: update the distance if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}
int main(){
int casos;
cin >> casos;
for(int i = 0; i < casos; i++){
    int verticestots;
    int verticeorigen;
    cin >> verticestots >> verticeorigen;
    vector<vector<pair<int,int>>> conexionesconpeso(verticestots);
    vector<int> distancia(verticestots,0);
    vector<int> parent(verticestots,-1);
    cin.ignore();
     string linea;
    for(int j = 0; j < verticestots; j++){
        getline(cin,linea);
        istringstream iss(linea);
        int conexionesvert;
        int destino;
        int peso;
        iss >> conexionesvert;
        while(iss >> destino >> peso){
            conexionesconpeso[j].push_back({destino,peso});
        }
    }
    dijkstra(verticeorigen,conexionesconpeso,distancia,parent);
    for(int h = 0; h < verticestots;h++){
        if(h == verticeorigen){
            continue;
        }
        else if(distancia[h] == numeric_limits<int>::max()){
            continue;
        }
        vector<int> caminobest;
        cout << h << ':' <<endl;
        cout << "riesgo " << distancia[h] << endl;
        int lastone = h;
    while(lastone != -1){//si llego a -1 es el inicio, voy de final -> inicio
        caminobest.push_back(lastone);
        lastone = parent[lastone];//voy y reviso quien es el padre del ultimo, y luego 
        //el padre de ese, y asi hasta llegar al inicio
    }
    for(int f = 1; f < caminobest.size(); f++){
        if(f == caminobest.size() - 1){
            cout << caminobest[f] << endl;
            continue;
        }
        cout << caminobest[f] << " <- ";
    }
    }
}
return 0;    
}
