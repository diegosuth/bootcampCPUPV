#include <bits/stdc++.h>
using namespace std;
using pdi = pair<double,int>;
void dijkstra(int source,int verticestots ,const vector<vector<pdi>>& adj, vector<double>& dist) {
    // priority queue
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    // Initialize distances all vertices as infinite
    dist[source] = 0.0; // Distancia al nodo origen es 0
    pq.push({0.0, source});
    while (!pq.empty()) {
        double d = pq.top().first; //distancia de este nodo
        int u = pq.top().second; //nodo a analizar
        pq.pop(); 

       //optimizacion para skipear not worth
        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            double weight = edge.first;//distancia nodo vecino
            int v = edge.second; //nodo vecino
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v],v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int verticestots;
    int edges;
    double distanciamax;
    cin >> verticestots >> edges >> distanciamax;
    string originaname;
    string originbname;
    vector<vector<pdi>> conexiones(verticestots);
    vector<double> distanciadesdea(verticestots,numeric_limits<double>::infinity());
    vector<double> distanciadesdeb(verticestots,numeric_limits<double>::infinity());
    unordered_map<string,int> nametonumber;//translator from string
    unordered_map<int,string> numbertoname;//translator to string
    for(int i = 0; i < verticestots; i++){
        string lugar;
        cin >> lugar;
        nametonumber[lugar] = i;
        numbertoname[i] = lugar;
    }
    for(int d = 0; d < edges; d++){
        string lugara;
        string lugarb;
        double weight;
        int a;
        int b;
        cin >> lugara >> lugarb >> weight;
        a = nametonumber[lugara];
        b = nametonumber[lugarb];
        conexiones[a].push_back({weight,b});
        conexiones[b].push_back({weight,a});
    }
    int casos;
    cin >> casos;
    for(int g = 0; g < casos; g++){
        cin >> originaname >> originbname;
        int origina = nametonumber[originaname];
        int originb = nametonumber[originbname];
        unordered_map<int,int> coincidencias;
        vector<double> distanciadesdea(verticestots,numeric_limits<double>::infinity());
        vector<double> distanciadesdeb(verticestots,numeric_limits<double>::infinity());
        dijkstra(origina,verticestots,conexiones,distanciadesdea);
        dijkstra(originb,verticestots,conexiones,distanciadesdeb);
        vector<int> coincidenciasfinales;
        for(int i = 0; i < verticestots; i++){
            if(abs(distanciadesdea[i] - distanciadesdeb[i]) <= distanciamax+1e-9){
                coincidenciasfinales.push_back(i);
            }
        }
        cout << coincidenciasfinales.size() << endl;
        vector<string> lugaresfinalessorted;
        for(int d = 0; d < coincidenciasfinales.size(); d++){
            lugaresfinalessorted.push_back(numbertoname[coincidenciasfinales[d]]);
        }
        sort(lugaresfinalessorted.begin(),lugaresfinalessorted.end());
        for(const string& s : lugaresfinalessorted){
            cout << s << endl;
        }
    }  
    return 0;
}