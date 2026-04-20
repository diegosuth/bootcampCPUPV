#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
void dijkstra(int source, const vector<vector<pii>>& adj, vector<int>& dist,vector<int>& parent) {
    int V = adj.size(); // vértices en el grafo
    // Cola de prioridad
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Inicializa distances all vertices as infinite
    int contador = 0;
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
                contador = 0;
            }
            else if(dist[u]+ weight == dist[v]){
                contador++;
            }
        }
    }
    if(contador > 0){
        cout << contador + 1 << endl;
    }
    else{
        cout << contador << endl;
    }
}
int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int verticestots;
        int conexionestots;
        int casa = 0;
        cin >> verticestots >> conexionestots;
        vector<vector<pii>> conexiones(verticestots);
        vector<int> distancia(verticestots,0);
        vector<int> parent(verticestots,-1);
        int universidad = verticestots - 1;
        for(int j = 0;j < conexionestots; j++){
            int a;
            int b;
            int weight;
            cin >> a >> b >> weight;
            a--;
            b--;
            conexiones[a].push_back({b,weight});
            conexiones[b].push_back({a,weight});
        }
        dijkstra(casa,conexiones,distancia,parent);
    }    
    
return 0;    
}
