#include <bits/stdc++.h>
using namespace std;

int main(){
    string username;
    cin >> username;
    int sumatoria = 0;
    set<char> p;
    for (int i = 0; i < username.length(); i++){
        p.insert(username[i]);
    }
    for (char c : p){
        sumatoria +=1;
    }
    if (sumatoria % 2 == 0){
        cout << "CHAT WITH HER!";
    }
    else {
        cout << "IGNORE HIM!";
    }
return 0;    
}
