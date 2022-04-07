#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int guardas(vector <int> posicao, int m) {
    int i = 1;
    int tamanho = posicao.size();
    vector <int> G;

    sort(posicao.begin(), posicao.end());
    G.push_back(posicao[0] + m);
    for (int j = 1; j < tamanho; j++) {
        if (posicao[j] > G[i - 1] + m) {
            G.push_back(posicao[j] + m);
            i += 1;
        }
    }
    return i;
}

int main() {
    int testes, n, m;
    cin >> testes;
    for (int i = 0; i < testes; i++) {
        cin >> n >> m;
        vector <int> posicao;
        if ( (1 < n) and (n < 1000000) and (1 < m) and (m < 1000) ) {
            for (int j = 0; j < n; j++) {
                int linha;
                cin >> linha;
                posicao.push_back(linha);
            }
            cout << guardas(posicao, m) << endl;
        }
    }
    return 0;
}
