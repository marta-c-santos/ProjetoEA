#include <iostream>
#include <vector>
using namespace std;

int pizza(int n, int somaT, vector <int> tempos) {

    int somatorio1 = somaT/2 + 1;
    int final = 0;
    vector <vector <bool>> DP(n + 1, vector<bool>(somatorio1, false));

    for (int i = 0; i <= n; i++) {
        DP[i][0] = true;
    }

    for (int j = 1; j <= somatorio1; j++) {
        DP[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= somatorio1; j++) {
            if (tempos[i - 1] > j) {
                DP[i][j] = DP[i - 1][j];
            } else {
                //DP[i][j] = DP[i - 1][j] | DP[i - 1][j - tempos[i - 1]];

                if (DP[i - 1][j]) {
                    DP[i][j] = DP[i - 1][j];
                } else {
                    DP[i][j] = DP[i - 1][j - tempos[i - 1]];
                }
            }

        }
    }
    for (int j = somatorio1 - 1; j >= 0; j--) {
        if (DP[n][j] == true) {
            final = j;
            break;
        }
    }

    return abs(somaT - 2*final);
}

int main() {
    int n, tempo;
    vector <int> tempos;

    while (cin >> n) {
        int somaT = 0;
        if (n >= 1 and n <= 100) {
            for (int i = 0; i < n; i++) {
                cin >> tempo;
                somaT += tempo;
                tempos.push_back(tempo);
            }
            cout << pizza(n, somaT, tempos) << "\n";
        }
        tempos.clear();
    }

    return 0;
}
