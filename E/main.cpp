#include <iostream>
#include <vector>
using namespace std;

int pizza(int n, int somaT, vector <int> tempos) {
4
    int somatorio1 = somaT/2;
    int final = 1;
    vector <vector <bool>> DP(n, vector<bool>(somatorio1, false));

    for (int i = 0; i < n; i++) {
        DP[i][0] = true;
    }

    for (int j = 0; j < somatorio1; j++) {
        DP[0][j] = false;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < somatorio1; j++) {
            if (tempos[i] > j) {
                DP[i][j] = DP[i - 1][j];
            } else {
                DP[i][j] = DP[i - 1][j] or DP[i - 1][j - tempos[i]];
            }
        }
    }
    for (int j = somatorio1; j >= 0; j--) {
        if (DP[n-1][j] == true) {
            final = j;
        }
    }
    return final;
}

int main() {
    int n, tempo;
    vector <int> tempos;

    while (cin >> n) {
        int somaT = 0;
        tempos.push_back(0);
        if (n >= 1 and n <= 100) {
            for (int i = 0; i < n; i++) {
                cin >> tempo;
                somaT += tempo;
                tempos.push_back(tempo);
            }
            cout << pizza(n, somaT, tempos) << "\n";
            tempos.clear();
        }
    }

    return 0;
}
