#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        
        // Buscamos el menor
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }

        // Cambiamos su posición
        if (min_idx != i) swap(arr[min_idx], arr[i]);
    }
}

int main(){
    int cantidad;
    cin >> cantidad;
    int arraynumeros[cantidad];
    for(int i = 0; i < cantidad ; i++){
        cin >> arraynumeros[i];
    }
    selectionSort(arraynumeros,cantidad);
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
