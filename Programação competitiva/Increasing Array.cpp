#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int a;
    long long m=0;
    cin >> a;
    int b[a];
 
    for(int i=0; i<a; i++){
        cin >> b[i];
    }
    
    for(int i=1; i<a; i++){
        while(b[i] < b[i-1]){
            b[i]++;
            m++;
        }
    }
    
    cout << m << "\n";
 
}