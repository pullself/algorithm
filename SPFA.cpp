#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 1000;

int h[MAX * 2], nxt[MAX * 2], to[MAX * 2], co[MAX * 2], dis[MAX], k = 0, book[MAX];
int n, m;

void insert(int u, int v, int c) {
	nxt[++k] = h[u];
	h[u] = k;
	to[k] = v;
	co[k] = c;
}

void SPFA(int s) {
	for (int i = 1; i <= n; i++) {
		book[i] = 0;
		dis[i] = 0x7fffffff;
	}
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	book[s] = 1;
	while (!que.empty()) {
		int cur = que.front();
		for (int i = h[cur]; i; i = nxt[i]) {

			if (dis[to[i]] > dis[cur] + co[i]) {
				dis[to[i]] = dis[cur] + co[i];
				if (book[to[i]] == 0) {
					que.push(to[i]);
					book[to[i]] = 1;
				}
			}
		}
		que.pop();
		book[cur] = 0;
	}
}

int main() {
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		insert(u, v, w);
	}
	int x;
	cin >> x;
	SPFA(x);
	for (int i = 1; i <= n; i++) {
		if (dis[i] > 100000) cout << "none" << " ";
		else cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}
