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

const int MAX = 1000;

int u[MAX], v[MAX], w[MAX], dis[MAX];
int n, m;

void Ford(int s) {
	for (int i = 1; i <= n; i++) dis[i] = 0x7fffffff;
	dis[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		bool check = 0;
		for (int j = 0; j < m; j++) {
			if ((dis[v[j]] >= 0x7fffffff) && (dis[u[j]] >= 0x7fffffff)) continue;
			else {
				if (dis[v[j]] > dis[u[j]] + w[j]) {
					dis[v[j]] = dis[u[j]] + w[j];
					check = 1;
				}
			}
		}
		if (!check) break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i];
	int x;
	cin >> x;
	Ford(x);
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (dis[i] > 100000) cout << "none" << " ";
		else cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}
