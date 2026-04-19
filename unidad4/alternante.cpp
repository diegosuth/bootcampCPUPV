#include <bits/stdc++.h>
using namespace std;

int main(){
    int largoarray;
    cin >> largoarray;
    string elementos;
    int array1[largoarray];
    int array2[largoarray];
    cin.ignore();
    getline(cin,elementos);
    istringstream iss(elementos);
    for (int i = 0;i<largoarray;i++){
        iss >> array1[i];
    }
    getline(cin,elementos);
    istringstream jss(elementos);
    for(int j = 0; j < largoarray;j++){
        jss >> array2[j];
    }
    for(int h; h<largoarray;h++){
        if (h % 2 == 1){
            int temp = 0;
            temp = array1[h];
            array1[h] = array2[h];
            array2[h] = temp;
        }
        else{
            continue;
        }
    }
    for(int k : array1){
        cout << k << " ";
    }
    cout << "\n";
    for(int l : array2){
        cout << l << " ";
    }
return 0;    
}
