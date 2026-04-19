#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    int y;
    cin >> x >> y;
    char mesa[x][y];
    char punto;
    for (int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            cin >> punto;
            mesa[i][j] = punto;
        }
    }
    for (int k = 0;k<x;k++){
        for (int l = 0;l<y;l++){
            if (mesa[k][l] == '#'){
                mesa[k][l] = 'm';
            }
            else{
                continue;
            }
        }
    }
    for (int m = 0; m < x;m++){
        for (int n = 0; n < y; n++){
            if (mesa[m][n] == 'm'){ 
                mesa[m][n] = '#';
                for (int p = 0; p < x; p++){//loop mojar horizontal
                    if (mesa[p][n] == 'm'){
                        continue;
                    }
                    else{
                    mesa[p][n] = '#';
                }}
                for (int r = 0; r < y; r++){//loop mojar vertical
                    if (mesa[m][r] == 'm'){
                        continue;
                    }
                    else{
                    mesa[m][r] = '#';
                }}
            }
        }
    }
    for (int s = 0; s < x; s++){
        for (int t = 0; t < y; t++){
            cout << mesa[s][t];
        }
    cout << "\n";   
    }

return 0;    
}
