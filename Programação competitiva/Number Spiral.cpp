#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    long long a, x, y;
    cin >> a;
    long long b[a];
 
    for(long long i=0; i<a;i++){
        cin >> x;
        cin >> y;
        if(x%2==0){
            if(y==1){
               b[i] = x*x;
            }else{
               if(y<=x){
                 b[i] = (x*x) - (y-1);
               }
            }
        }else{
          b[i] = ((x-1)*(x-1))+y;
        }
 
 
        if(y%2!=0){
          if(x==1){
            b[i] = y*y;
          }else{
            if(x<=y){
              b[i] = (y*y) - (x-1);
            }
          }  
        }else{
          if(y>=x){
            b[i] = ((y-1)*(y-1))+x;
          }
        }
    }
 
    for(long i=0; i<a; i++){
        cout << b[i] << "\n";
    }
 
}