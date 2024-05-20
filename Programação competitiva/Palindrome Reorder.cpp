#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  deque<char> s;
 
    char c;
    while (cin.get(c)) {
        if (c == '\n') {
            break; 
        }
        s.push_back(c);
    }
 
  deque<char> saida;
 
  int impar=0;
 
  map<char, long long> frequencia;
 
    for (char c : s) {
        frequencia[c]++;
    }
 
    for (auto it = frequencia.begin(); it != frequencia.end(); ++it) {
        if (it->second % 2 != 0) {
            impar++;
        }
    }
 
    if (impar > 1) {
        cout << "NO SOLUTION";
    } else {
        for (auto it = frequencia.rbegin(); it != frequencia.rend(); ++it) {
            if (it->second % 2 == 0) {
                while (it->second > 0) {
                    saida.push_front(it->first);
                    saida.push_back(it->first);
                    it->second -= 2;
                }
            } else {
                while (it->second > 0) {
                    saida.insert(saida.begin() + saida.size() / 2, it->first);
                    it->second--;
                }
            }
        }
        for (char c : saida) {
            cout << c;
        }
    }
 
    return 0;
}