#include <iostream>
#include <vector>
using namespace std;

int caminho(int n,  vector<vector<int>> arv, vector<vector<int>> per1) {
    int maxi = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            arv[i][j] = per1[i][j] + max(arv[i - 1][j - 1], arv[i - 1][j]);
            if (i == n - 1) { // ultimo caso
                if (arv[i][j] > maxi)
                    maxi = arv[i][j];
            }
        }
    }
    return maxi;
}

int main() {
    int numTestes, numLinhas, caminhoMax;
    cin >> numTestes;

    for (int i = 0; i < numTestes; i++) {
        cin >> numLinhas;
        vector<vector<int>> arv(numLinhas + 1, vector<int>(numLinhas + 1, 0));
        vector<vector<int>> per1(numLinhas + 1, vector<int>(numLinhas + 1, 0));

        for (int j = 1; j < numLinhas + 1; j++) {
            for (int k = 1; k < j + 1; k++) { //para fazer o "triangulo"
                int valor;
                cin >> valor;
                per1[j][k] = valor;
            }
        }
        caminhoMax = caminho(numLinhas + 1, arv, per1);
        cout << caminhoMax << endl;
    }
    return 0;
}
