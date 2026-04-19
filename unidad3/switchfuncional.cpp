#include <bits/stdc++.h>
using namespace std;

int main() {
    char brujula;
    cin >> brujula;
    switch (brujula) {
    case 'N':
        cout << "Norte" << endl;
        break;
    case 'E':
        cout << "Este" << endl;
        break;
    case 'S':
        cout << "Sur" << endl;   // <--
        break;
    case 'O':
        cout << "Oeste" << endl;
        break;
    case '1':
    case '2':
    case '3':
    case '4':
        cout << "Un número" << endl;
        break;
    default:
        cout << "Y entonces a donde miras?" << endl;
}
    return 0;
}

