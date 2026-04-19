#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int p;
    int a;
    string adivinanza;
    int t;
    cin >> n >> p;
    cin.ignore();
    getline(cin,adivinanza);
    istringstream iss(adivinanza);
    for (p; p > 0; p--){
        iss >> t;
        if (t == n){
            printf("1p ");
        }
        else if (abs(n-t) <= 5){
            printf("0.5p ");
        }
        else if (abs(n-t) <= 10){
            printf("0.25p ");
        }
        else {
            printf("0p " );
        }
    }



return 0;    
}