#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int a,c,d;
    cin >> a;
    int b[a-1];
    for (int i = 0; i < a - 1; i++){
        cin >> b[i];
    }
 
    d = sizeof(b) / sizeof(b[0]);
    
    sort(b, b + d);
 
    for (int i = 1; i <= a; i++){
        if(i != b[i-1]){
            c = i;
            break;
        }
    }
 
    cout << c << "\n";
}