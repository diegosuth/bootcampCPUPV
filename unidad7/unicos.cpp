#include <bits/stdc++.h>
using namespace std;
int main() {
    string palabra;
    int largosubstr;
    cin >> palabra;
    cin >> largosubstr;
    set<string> palabrasunicas;
    for(int i = 0; i < palabra.length(); i++){
        if(i > (palabra.length() - largosubstr)){
            break;
        }
        string temp;
        temp = palabra.substr(i,largosubstr);
        palabrasunicas.insert(temp);
    }
    cout << palabrasunicas.size() << endl;
    return 0;
}
