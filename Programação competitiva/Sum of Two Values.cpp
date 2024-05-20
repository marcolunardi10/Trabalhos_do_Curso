#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, x;
    cin >> n >> x;
    
    vector<long long> v(n);
    unordered_map<long long, long long> index;
 
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < x) {
            count++;
        }
    }
 
    if (count < 2) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    for (long long i = 0; i < n; i++) {
        index[v[i]] = i + 1; 
    }
 
    for (long long i = 0; i < n; i++) {
        long long complemento = x - v[i];
        
        if (index.find(complemento) != index.end()) {
            long long j = index[complemento];
            
            if (j != i + 1) {
                cout << i + 1 << " " << j << endl;
                return 0;
            }
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}