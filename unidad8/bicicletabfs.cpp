#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
void dijkstra(int source,int obj, const vector<vector<pii>>& adj, vector<long long>& dist) {
    int V = adj.size(); // vértices en el grafo
    // Cola de prioridad
    priority_queue<pii, vector<pii>,greater<pii>> pq;
    // Inicializa distances all vertices as infinite
    int contador = 0;
    dist.assign(V, numeric_limits<int>::max());
    dist[source] = 0; // Distancia al nodo origen es 0
    pq.push({0,source});
    // Procesa la cola de propiedad
    while (!pq.empty()) {
        int d = pq.top().first;  // Get the distance of the vertex
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop(); // Remove the vertex from the priority queue
        // Skip processing if the distance is not optimal (stale entry)
        if (d > dist[u]) continue;
        // Traverse all neighbors of the vertex u
        for (const auto& edge : adj[u]) {
            int weight = edge.first; // Edge weight
            int v = edge.second;    // Neighbor vertex

            // Relaxation step: update the distance if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                if(v == obj){
                    contador = 1;
                }
            }
            else if(dist[u] + weight == dist[v]){
                if(v == obj){
                    contador++;
                }
            }
        }
    }
    cout << contador << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int verticestots;
        int conexionestots;
        int casa = 0;
        cin >> verticestots >> conexionestots;
        vector<vector<pii>> conexiones(verticestots);
        vector<long long> distancia(verticestots);
        for(int j = 0;j < conexionestots; j++){
            int a;
            int b;
            long long weight;
            cin >> a >> b >> weight;
            a--;
            b--;
            conexiones[a].push_back({weight,b});
            conexiones[b].push_back({weight,a});
        }
        dijkstra(casa,verticestots-1,conexiones,distancia);
    }    
    
return 0;    
}
