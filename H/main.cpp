#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(int v, vector<vector<int>> teste, vector <int> color) {
    //Q is an empty queue
    color[v] = 1;
    queue <int> Q;
    Q.push(v);

    while (!Q.empty()) { // Q nao esta vazio
        int t = Q.front();
        Q.pop();

        int tam = teste[t].size();
        for (int k = 0; k < tam; k++) { //rever variaveis do for
            int u = teste[t][k];
            if (color[u] == -1) { //u nao tem cor
                color[u] = 1 - color[t];
                Q.push(u);

            } else if (color[u] == color[t]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m, id, estacao;
    bool final = false;

    while (cin >> n >> m) {
        vector <vector<int>> teste(n);
        vector <int> color(n, -1);

        if (n <= 500 and m <= 65000) {
            for (int i = 0; i < m; i++) {
                cin >> id >> estacao;
                teste[id - 1].push_back(estacao - 1);
                teste[estacao - 1].push_back(id - 1);
            }
            for (int j = 0; j < n; j++) {
                if (color[j] == -1) {
                    final = BFS(j, teste, color);
                    if (!final)
                        break;
                }
                
            }

            if (!final) {
                cout << "NO\n";
            } else {
                cout << "NOT SURE\n";
            }
        }
    }
    return 0;
}

/*
5 4
1 2
1 4
1 5
2 3
5 5
1 3
2 4
2 5
3 4
4 5

NOT SURE
NO
*/
