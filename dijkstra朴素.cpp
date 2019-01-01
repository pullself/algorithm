#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
using namespace std;

const int maxn = 1000;
const int inf = 0x7fffffff;

int n, m;
int e[maxn][maxn], dis[maxn];
int book[maxn];

void dij(int s) {
	for (int i = 1; i <= n; i++) dis[i] = e[s][i];
	for (int i = 1; i <= n; i++) book[i] = 0;
	book[s] = 1;
	dis[s] = 0;

	for (int i = 1; i <= n - 1; i++) {
		int min = inf;
		int u;
		for (int j = 1; j <= n; j++) {
			
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (int v = 1; v <= n; v++) {
			if (e[u][v] < inf && book[v] == 0) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			e[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u][v] = w;
	}
	int x;
	cin >> x;
	dij(x);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	return 0;
}
