#include <bits/stdc++.h>
using namespace std;
int n;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int contador = 0;
bool isValid(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < n;
}

int dfs(int r,int c, vector<string> &grid, vector<vector<bool>> &visited, int pasos){
    if(grid[r][c] == 'C'){
        return pasos;
    }
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        int newR = r + dr[i];
        int newC = c + dc[i];

        if(isValid(newR,newC) && !visited[newR][newC] && grid[newR][newC] != '.'){
            int resultado = dfs(newR,newC,grid,visited,pasos+1);
            if(resultado != -1){
                return resultado;
            }
        }
    }
    return -1;
}

int main(){
    cin >> n;
    vector<string> grid(n);
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int startr;
    int startc;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'R'){
                startr = i;
                startc = j;
            }
        }
    }
    int saltostotales = dfs(startr,startc,grid,visited,0);
    if(saltostotales != -1){
        cout << saltostotales<< endl;
    }
    else{
        cout << "No hay camino" << endl;
    }

return 0;    
}
