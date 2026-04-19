#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
}

int main(){
    int cantidad;
    cin >> cantidad;
    int arraynumeros[cantidad];
    for(int i = 0; i < cantidad ; i++){
        cin >> arraynumeros[i];
    }
    bubbleSort(arraynumeros,cantidad);
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
