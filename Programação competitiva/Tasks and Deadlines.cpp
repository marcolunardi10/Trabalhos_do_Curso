#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, a, d, t=0, r=0, i;
    cin >> n;
    vector<pair<long long, long long>> v;
 
    for(long long i=0; i<n; i++){
        cin >> a >> d;
        v.push_back({a, d});
    }
 
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); ++it){
        i = it->first;
        while(i > 0){
            t++;
            i--;
        }
        r= r + (it->second - t);
    }
 
    cout << r;
 
 
 
    return 0;
}
