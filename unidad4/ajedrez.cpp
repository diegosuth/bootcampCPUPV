#include <bits/stdc++.h>
using namespace std;

int main(){
    char tableroreal[8][8] = 
    {{'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}};
    int casos;
    char tablerotest[8][8];
    string linea;
    cin >> casos;
    cin.ignore();
    for (int i = 0; i < casos; i++){
        for (int j = 0; j < 8; j++){
            getline(cin, linea);
            istringstream iss(linea);
            for (int k = 0; k < 8; k++){
                iss >> tablerotest[j][k];
                if (tableroreal[j][k] != tablerotest[j][k]){
                    tablerotest[j][k] = 'X';
                }
                cout << tablerotest[j][k];
            }
        cout << endl;
        }
    }
return 0;    
}
