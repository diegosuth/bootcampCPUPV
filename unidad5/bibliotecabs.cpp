#include <bits/stdc++.h>
using namespace std;
int bs(int low, int high, int arr[],int x){
    if (high >= low){
        int mid = low + ((high - low)/ 2);
        if (x == arr[mid]){
            return mid;
        }
        if (x < arr[mid]){
           return bs(low,mid - 1,arr,x);
        }
        if (x > arr[mid]){
            return bs(mid+1,high,arr,x);
        }
    }
    return -1;
}
int main(){
    int libroabuscar;
    int cantidadlibros;
    int libroencontrado;
    cin >> cantidadlibros;
    int libros[cantidadlibros];
    for(int i = 0; i < cantidadlibros; i++){
        cin >> libros[i];
    }
    sort(libros,libros + cantidadlibros);
    int cantidadconsultas;
    cin >> cantidadconsultas;
    for(int j = 0; j < cantidadconsultas;j++){
        cin >> libroabuscar;
        libroencontrado = bs(0,cantidadlibros - 1,libros,libroabuscar);
        if (libroencontrado != -1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout <<endl;
    }
return 0;    
}
