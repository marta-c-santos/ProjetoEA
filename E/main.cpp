#include <iostream>
#include <vector>
using namespace std;

int somatorio(int valorN, vector <int> tempos) {
    int soma1 = 0;
    for (int k = 0; k < valorN; k++) {
        soma1 += tempos[k];
        cout << "tempos: " << tempos[k] << "\n";
    }
    soma1 = soma1 / 2;

    cout << "entra no somatorio\t" << soma1 << "\n";
    return soma1;
}

int pizza(int n, vector <int> tempos) {

    cout << "entra aqui1\n";
    int somatorio1 = 0;
    somatorio1 = somatorio(n, tempos);
    vector <vector <bool>> DP(n + 1, vector<bool>(somatorio1, false));
    int final = 2;

    for (int i = 0; i < n; i++) {
        DP[i][0] = true;
    }

    /*
    for (int j = 0; j < somatorio1; j++) {
        DP[0][j] = false;
    }*/

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < somatorio1; j++) {
            if (tempos[i] > j) {
                cout << "entra no if\n";
                DP[i][j] = DP[i - 1][j];
                cout << "entra no if fim\n";
            } else {
                cout << "entra no else\n";
                DP[i][j] = DP[i - 1][j] or DP[i - 1][j - tempos[i]];
                cout << "entra no else fim\n";
            }
        }
    }
    cout << "entra aqui2\n";
    for (int j = somatorio1; j < 0; j--) {
        if (DP[n][j] == true) {
            final = j;
        }
    }
    cout << "entra aqui3\n";
    return final;
}

int main() {
    int n;

    while (cin >> n) {
        if (n >= 1 and n <= 100) {
            vector <int> tempos(n);
            for (int i = 0; i < n; i++) {
                cin >> tempos[i];
            }
            cout << pizza(n, tempos) << "\n";
        }
    }

    return 0;
}
