#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        int nodos;
        int edges;
        cin >> nodos >> edges;
        vector<int> adj[nodos];
        for(int d = 0; d < edges; d++){
            int a;
            int b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int y; //the middle node the leaf is connected to
        int x;//the size of the adj list of the parent of y, x.(aka how many connections the root has)
        int max = 0;
        for(int d = 0; d< nodos; d++){//first find a leaf to know its parent, therefore y(middle node)
            if(adj[d].size() == 1){
                y = adj[adj[d][0]].size() - 1;//using the leaf as index, the column of its parent it's the connections
                //of the middle node, so its fundamental to substract 1 since the root doesnt count for y
                //for(int f = 0; f < adj[adj[d][0]].size();f++){//alt code for finding root between middle connection
                    //if(adj[adj[adj[d][0]][f]].size() > max){
                        //max = adj[adj[adj[d][0]][f]].size();
                    //}
                //}
                break;
            }
        }
        x = edges / (y + 1);
        //alternatively:
        //x = max;
        //totaledges = x + (x * y) since there are 3 levels, the total edges are the 
        //amount connected to the root x + these x nodes times their y amount of leafs
        //aka the size of the parent of y * x
        cout << x << ' ' << y << endl;
    }
    
    return 0;    
}