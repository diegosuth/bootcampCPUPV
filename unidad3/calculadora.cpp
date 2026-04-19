#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int d;
    string o;
    double decimal;
    int resultado;
    cin >> n >> o >> d;
    if (o == "+"){
        resultado = n + d;
        cout << resultado << endl;
    }
    if (o == "-"){
        resultado = n - d;
        cout << resultado << endl;
    }
    if (o == "*"){
        resultado = n * d;
        cout << resultado << endl;
    }
    if (o == "/"){
        if (d == 0) cout << "ERROR" <<endl;
        else {
        decimal = ((double)n) / ((double)d);
        cout<<setprecision(2) <<fixed << decimal << endl; }
    }
    return 0;
}