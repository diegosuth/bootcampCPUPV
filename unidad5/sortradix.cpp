#include <bits/stdc++.h>
using namespace std;

// --- Funciones auxiliares del Radix (SOLO PARA POSITIVOS) ---

int getMax(vector<int>& arr) {
    if (arr.empty()) return 0;
    int max = arr[0];
    for (int x : arr)
        if (x > max) max = x;
    return max;
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Conteo
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Acumulativa
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Ordenar en output
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar de vuelta
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Esta función solo ordena positivos
void radixSortCore(vector<int>& arr) {
    if (arr.empty()) return;
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

// --- FUNCIÓN PRINCIPAL QUE MANEJA NEGATIVOS ---
void radixSortSigned(vector<int>& arr) {
    vector<int> positivos;
    vector<int> negativos;

    // 1. Separar
    for (int x : arr) {
        if (x >= 0) {
            positivos.push_back(x);
        } else {
            // Guardamos el valor absoluto para poder ordenarlo
            negativos.push_back(abs(x));
        }
    }

    // 2. Ordenar ambas listas por separado
    radixSortCore(positivos);
    radixSortCore(negativos);

    // 3. Reconstruir el array original
    // Primero van los negativos. OJO: Debemos recorrerlos al revés.
    // Si tenemos -2 y -5. Absolutos ordenados: 2, 5.
    // Necesitamos que quede: -5, -2.
    // Por eso recorremos el vector 'negativos' desde el final hacia el principio.
    int index = 0;
    
    for (int i = negativos.size() - 1; i >= 0; i--) {
        arr[index++] = -negativos[i]; // Devolvemos el signo negativo
    }

    for (int i = 0; i < positivos.size(); i++) {
        arr[index++] = positivos[i];
    }
}

int main() {
    int cantidad;
    cin >> cantidad;
    
    // Usamos vector porque facilita la vida, pero funciona igual que array
    vector<int> numeros; 
    int temp;
    for (int i = 0; i < cantidad; i++) {
        cin >> temp;
        numeros.push_back(temp);
    }

    radixSortSigned(numeros);

    int contador = 0;
    for(int f : numeros){
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