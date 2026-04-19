#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n)
{
    int key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int cantidad;
     cin >> cantidad;
    int arraynumeros[cantidad];
    for(int i = 0; i < cantidad ; i++){
        cin >> arraynumeros[i];
    }
    insertionSort(arraynumeros, cantidad);
    int contador = 0;
    for(int f : arraynumeros){
        if(contador == cantidad-1){
            cout << f << endl;
        }
        else{
            cout << f << ' ';
        }
        contador++;
    }
return 0;    
}
