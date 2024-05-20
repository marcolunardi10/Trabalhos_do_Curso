#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
 long long n,r1=0,r2=0;
 cin >> n;
 
 vector<long long> v1, v2;
 
 for(long long i=n; i>0; i--){
    if(r1<=r2){
      r1 += i;
      v1.push_back(i);
    }else{
      r2 += i;
      v2.push_back(i);
    }
 }
 
  if(r2 == r1){
    cout << "YES" << endl;
    cout << v1.size() << endl;
    for(long long i : v1){
      cout << i << " ";
    }
    cout << endl;
    cout << v2.size() << endl;
    for(long long i : v2){
      cout << i << " ";
    }
  }else{
    cout << "NO";
  }
 
}