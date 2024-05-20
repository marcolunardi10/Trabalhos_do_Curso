#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    long long n, m;
    cin >> n >> m;
 
    multiset<long long> prices;
    for (long long i = 0; i < n; i++) {
        long long price;
        cin >> price;
        prices.insert(price);
    }
 
    for (long long i = 0; i < m; i++) {
        long long max_price;
        cin >> max_price;
        
        auto it = prices.upper_bound(max_price);
        if (it != prices.begin()) {
            --it;
            cout << *it << endl;
            prices.erase(it); 
        } else {
            cout << -1 << endl;
        }
    }
 
    return 0;
}