#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
   string a;
   int b=1, maior=1;
   cin >> a;
 
    for(int i=0; i<a.length(); i++){
        if(a[i] == a[i+1]){
            b++;
            if(b > maior){
                maior = b;
            }
        }else{
            b = 1;
        }
    }
    
    cout << maior;
 
}