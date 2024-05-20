#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int a,s;
    cin >> a;
    vector<int> b;
 
    if(a == 2 || a==3){
        s=1;
    }
    else{
        s=0;
        for (int i = 2; i <= a; i += 2) {
            b.push_back(i);
        }
        for (int i = 1; i <= a; i += 2) {
            b.push_back(i);
        }
    }    
 
    if(s!=1){
        for(int i=0; i<a; i++){
            cout << b[i] << " ";
        }
    }
    else{
        cout << "NO SOLUTION";
    }
}