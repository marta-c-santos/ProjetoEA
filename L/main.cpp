#include <iostream>
#include <vector>
using namespace std;

int intcubes(int n, vector<vector<int>> C) {
    int Ix_min, Iy_min, Iz_min;
    int Ix_max, Iy_max, Iz_max;
    int final;

    for (int i = 1; i < n; i++) {
        Ix_min = max(Ix_min, C[i][0]);
        Iy_min = max(Iy_min, C[i][1]);
        Iz_min = max(Iz_min, C[i][2]);
        Ix_max = min(Ix_max, C[i][0] + C[i][3]);
        Iy_max = min(Iy_max, C[i][1] + C[i][3]);
        Iz_max = min(Iz_max, C[i][2] + C[i][3]);
    }
    cout << Ix_min << " -- " << Iy_min << " -- " << Iz_min << "\n";
    cout << Ix_max << " -- " << Iy_max << " -- " << Iz_max << "\n";
    final = max(0, Ix_max - Ix_min) * max(0, Iy_max - Iy_min) * max(0, Iz_max - Iz_min);
    return final;
}

int main() {
    int n, x, y, z, size;
    cin >> n;
    vector <vector <int>> coord;
    if (2 < n and n < 100001) {
        cout << "aqui \n";
        for (int i = 0; i < n; i++) {
            cout << "aqui22222\n";
            cin >> x >> y >> z >> size;
            cout << "depois\n";
            coord[i][0] = x;
            coord[i][1] = y;
            coord[i][2] = z;
            coord[i][3] = size;
            cout << "depois 2222222\n";
        }
        cout << "antes\n";
        int fim = intcubes(n, coord);
        cout << fim << endl;
    }

    return 0;
}
