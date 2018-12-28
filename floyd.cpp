#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1000;

int e[MAX][MAX];
int n, m;

void Floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
}

int main() {
    cin >> n >> m;
    const int inf = 100000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) e[i][j] = 0;
            else e[i][j] = inf;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        e[u][v] = w;
        e[v][u] = w;
    }
    Floyd();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << e[i][j] << " ";
    return 0;
}