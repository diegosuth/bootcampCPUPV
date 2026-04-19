#include <bits/stdc++.h>
using namespace std;
int *a;

void quicksort(int l, int r) { // Ambos índices válidos
    if (r-l < 1) return;
    int pivot = a[r]; // En este caso, cojemos el último
    int i = l, j = l;
    
    while (j <= r) {
        // Reemplazamos si es menor que el pivot
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            ++i;
        }
        ++j;
    }
    
    // Cambia el pivot por su posición ordenada
    swap(a[i], a[r]);
    
    // Ordena ambos lados
    quicksort(l, i-1);
    quicksort(i+1, j-1);

}

int main(){
    int cantidad;
    cin >> cantidad;
    int arraynumeros[cantidad];
    for(int i = 0; i < cantidad ; i++){
        cin >> arraynumeros[i];
    }
    a = arraynumeros;
    quicksort(0,cantidad-1);
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
