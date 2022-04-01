#include <iostream>
#include <vector>
using namespace std;

void mis(int n, int v, int size, vector <vector <int>> membros) {
    //mudar isto
    int best = 0;
    vector <int> neighbor;

    if (size > best) {
        best = size;
    }
    int UB = 0;
    for (int i = v + 1; i < n; i++) {
        if (neighbor[i] == 0) {
            UB = UB + 1;
        }
    }
    if ( (size + UB) <= best ) {
        return;
    }
    for (int i = v + 1; i < n; i++) {
        //if { i, v } pertencem a E {
            neighbor[i] = neighbor[i] + 1;
        //}
    }

    for (int i = v + 1; i < n; i++) {
        if (neighbor[i] == 0) {
            mis(n, i, size + 1, membros);
        }
    }

    for (int i = v + 1; i < n; i++) {
        //if { i, v } pertencem a E {
            neighbor[i] = neighbor[i] - 1;
        //}
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector <vector <int>> membros;
        for (int i = 0; i < m; i++) {
            cin >> membros[i][0] >> membros[i][1];
        }
        mis(n, 0, m, membros);
    }

    return 0;
}
