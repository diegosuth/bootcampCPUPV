#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
void dijkstra(int source, const vector<vector<pii>>& adj, vector<long long>& dist, int velocidad, int tiempototal,vector<int>& visitas) {
    int V = adj.size(); // total vertex
    // priority queue
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Initialize distances all vertices as infinite
    dist.assign(V, numeric_limits<int>::max());
    dist[source] = 0; // Distancia al nodo origen es 0
    pq.push({0, source});
    while (!pq.empty()) {
        int d = pq.top().first; // Get the distance of the vertex
        int u = pq.top().second; // Get the vertex with the smallest distance 
        pq.pop(); 

        // Skip processing if the distance is not optimal (stale entry)
        if (d > dist[u]) continue;

        // Traverse all neighbors of the vertex u
        for (const auto& edge : adj[u]) {
            int weight = edge.first;
            int v = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for(int d = 0; d < dist.size(); d++){
        if(dist[d] <= (1LL * tiempototal * velocidad)){
            visitas.push_back(d);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int verticestots;
    int duracioncarrera;//en segundos
    int velocidada; //metros/segundos
    int velocidadb;
    vector<int> visitasdea;
    vector<int> visitasdeb;
    cin >> verticestots >> duracioncarrera >> velocidada >> velocidadb;
    vector<vector<pii>> conexiones(verticestots);
    vector<long long> distancia(verticestots,numeric_limits<int>::max());
    int edges = verticestots - 1;
    int inicioa;
    unordered_map<int,int> coincidencias;
    int iniciob;
    cin >> inicioa >> iniciob;
    inicioa--;
    iniciob--;
    for(int i = 0; i < edges; i++){
        int a;
        int b;
        int weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        conexiones[a].push_back({weight,b});
        conexiones[b].push_back({weight,a});
    }
    dijkstra(inicioa,conexiones,distancia,velocidada,duracioncarrera,visitasdea);
    dijkstra(iniciob,conexiones,distancia,velocidadb,duracioncarrera,visitasdeb);
    for(int d : visitasdea){
        coincidencias[d]++;
    }
    int contador = 0;
    vector<int> coincidenciasfinales;
    for(int f : visitasdeb){
        if(coincidencias[f] > 0){
            contador++;
            coincidenciasfinales.push_back(f);
        }
    }
    cout << contador << "\n";
    int countalt = 0;
    for(int g : coincidenciasfinales){
        if(countalt == coincidenciasfinales.size() -1){
            cout << g + 1<< endl;
        }
        else{
            cout << g +1<< ' ';
        countalt++;
        }
    }
    
    return 0;    
}