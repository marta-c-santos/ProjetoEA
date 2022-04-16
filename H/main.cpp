#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(G, int v) {
    //Q is an empty queue
    color(v) = 1;
    enqueue(v, Q);
    while () { // Q nao esta vazio
        int t = dequeue(Q);
        for (int u = 0; u < ; u++) { //rever variaveis do for
            if () { //u nao tem cor
                color(u) = 1 - color(t);
                enqueue(u, Q);

            } else if (color(u) == color(t)){
                return false;
            }
        }

    }
    return true;
}

int main() {
    //usar arraylist -> tipo lista
    
    int n, m, id, estacao;
    bool final;
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
                }
            }

            final = BFS();
            if (final) {
                cout << "NO\n";
            } else {
                cout << "NOT SURE\n";
            }
        }
    }

