#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 200005;

int pre[50050], ran[50050], ans = 0;

struct edge {
	int x, y;
	int w;
}e[MAX];

bool cmp(edge a, edge b) {
	if (a.w != b.w) return a.w < b.w;
	else return a.x < b.x;
}

void make_pre(int i)
{
	pre[i] = i;
	ran[i] = 0;
}

int find_pre(int i)
{
	if (pre[i] == i)
		return pre[i];
	return  pre[i] = find_pre(pre[i]);
}

int unite(int x, int y, int w) {
	int rootx, rooty;
	rootx = find_pre(x);
	rooty = find_pre(y);
	if (rootx == rooty) return 0;
	if (ran[rootx] > ran[rooty]) {
		pre[rooty] = rootx;
	}
	else {
		if (ran[rootx] == ran[rooty]) ran[rooty]++;
		pre[rootx] = rooty;
	}
	ans += w;
	return 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) make_pre(i);
	for (int i = 1; i <= m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		e[i].x = x;
		e[i].y = y;
		e[i].w = w;
	}
	sort(e + 1, e + m + 1, cmp);
	ans = 0;
	int count = 0;
	for (int i = 1; i <= m; i++) {
		int flag = unite(e[i].x, e[i].y, e[i].w);
		if (flag) count++;
		if (count == n - 1) break;
	}
	cout << ans << endl;
	return 0;
}
