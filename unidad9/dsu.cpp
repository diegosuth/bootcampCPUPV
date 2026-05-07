#include <bits/stdc++.h>
using namespace std;
int numnodos;
vector<int> parent(numnodos);
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
    // En una línea, actualizar parent[v] y devolver el valor
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        
    }
    return 0;    
}