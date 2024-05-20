#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Evento {
    int tempo;
    char tipo; 
    
  
    bool operator<(const Evento& outro) const {
        if (tempo == outro.tempo)
            return tipo < outro.tipo; 
        return tempo < outro.tempo;
    }
};
 
int maxClientesNoRestaurante(int n, vector<pair<int, int>>& clientes) {
   
    vector<Evento> eventos;
    
   
    for (int i = 0; i < n; i++) {
        int chegada = clientes[i].first;
        int saida = clientes[i].second;
        eventos.push_back({chegada, 'a'});
        eventos.push_back({saida, 'd'});
    }
    
    
    sort(eventos.begin(), eventos.end());
    
    int clientesAtuais = 0;
    int maxClientes = 0;
    
    for (const auto& evento : eventos) {
        if (evento.tipo == 'a') {
            clientesAtuais++;
            maxClientes = max(maxClientes, clientesAtuais);
        } else {
            clientesAtuais--;
        }
    }
    
    return maxClientes;
}
 
int main() {
    int n; 
    cin >> n;
    
    vector<pair<int, int>> clientes(n);
 
    for (int i = 0; i < n; i++) {
        cin >> clientes[i].first >> clientes[i].second;
    }
 
    int maxClientes = maxClientesNoRestaurante(n, clientes);
 
    cout <<  maxClientes;
    
    return 0;
}
