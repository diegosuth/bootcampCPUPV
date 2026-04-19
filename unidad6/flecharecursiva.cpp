#include <bits/stdc++.h>
using namespace std;
void iterate(int n){
    if(n == 0){
        return;
    }
    cout << '#';
    iterate(n-1);
}
void baditerate(int n,int o){
    if(n == 0 || n == o){
        return;
    }
    cout << '#';
    iterate(n-1);
}
void draw(int n, int o){
    if(n == 0){
        return;
    }
    baditerate(n,o);
    cout << endl;
    draw(n-1,o);
}
void inversedraw(int n,int o){
    if (n == 0){
        return;
    }
    if(n != o){
    inversedraw(n-1,o);
    iterate(n);
    cout << endl;
    }
    else{
    inversedraw(n-1,o);
    iterate(n);
    }
}
int main(){
    int numero;
    int origin;
    cin >> numero;
    origin = numero;
    inversedraw(numero,origin);
    draw(numero,origin);
return 0;    
}
