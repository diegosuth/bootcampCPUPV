#include <bits/stdc++.h>
using namespace std;
int R;
int C;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool isValid(int r, int c){
    return r >= 0 && r < R && c >= 0 && c < C;
}

int dfs(int r, int c, vector<string>& grid, vector<vector<bool>>& visited, int pasos){
    if(grid[r][c] == 'S'){
        return pasos;
    }
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        int newR = r + dr[i];
        int newC = c + dc[i];
        
        if(isValid(newR,newC) && !visited[newR][newC] && grid[newR][newC] != '#'){
            int resultado = dfs(newR,newC, grid,visited,pasos + 1);
            if(resultado != -1){
                return resultado;
            }
        }
    }
    return -1;
}


int main(){
    cin >> C >> R;
    vector<string> grid(R);
    vector<vector<bool>> visited(R,vector<bool>(C,false));
    int startR;
    int startC;
    for(int i = 0; i < R; i++){
        cin >> grid[i];
        for(int j = 0; j < C; j++){
            if(grid[i][j] == 'E'){
                startR = i;
                startC = j;
            }
        }
    }
    int resultado = dfs(startR,startC,grid,visited,1);
    if(resultado != -1){
        cout << resultado << endl;
    }
    else{
        cout << "Estas atrapado para siempre" << endl;
    }
return 0;    
}
