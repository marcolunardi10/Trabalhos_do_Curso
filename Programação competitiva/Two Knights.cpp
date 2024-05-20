#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    long long n;
    cin >> n;
 
    cout << 0 << "\n";
    for(long long i=2;i<=n;i++){
        cout << (i*i)*(i*i-1)/2 - (4*(i-2)*(i-1)) << "\n";
    }
    
}