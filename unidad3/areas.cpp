#include <bits/stdc++.h>
using namespace std;

int main() {
    int i;
    int x;
    double a;
    double b;
    string line;
    const double pi = 3.141592;
    cin >> i;
    cin.ignore();
    cout << setprecision(5) << fixed;
    while (i > 0) {
            getline(cin,line);
            istringstream iss(line); 
            iss >> x >> a;
            if (x == 1){
            cout << pi * pow(a,2)<< "\n";
            i -= 1;
            }
            else if (x == 2){
            cout << a * a <<"\n";
            i -= 1;
            }
            else if (x == 3){
            iss >> b;
            cout << a * b << "\n";
            i -= 1;
            }
            else {
            iss >> b;
            cout << (a * b) / 2 << "\n"; 
            i -= 1;    
            }
    }
    return 0;
}