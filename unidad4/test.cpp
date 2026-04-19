#include <bits/stdc++.h>
using namespace std;
int mas(){
    int y = 5;
    y++;
    return y;
}
int menos(){
    static int y = 15;
    y--;
    return y;
}
int main(){
    int x = 0;
    int w = 0;
    for(int i = 0; i < 3; i++){
        x = mas();
        w = menos();
        cout << x << endl;
    }
    cout << x << " " << w;
return 0;    
}
