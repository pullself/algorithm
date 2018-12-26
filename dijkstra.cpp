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

int h[MAX * 2], to[MAX * 2], nxt[MAX * 2], co[MAX * 2], dis[MAX], k = 0, n, m;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

void insert(int u,int v,int c) {
    nxt[++k] = h[u];
    h[u] = k;
    to[k] = v;
    co[k] = c;
    nxt[++k] = h[v];
    h[v] = k;
    to[k] = u;
    co[k] = c;
}

void dij(int s) {
    for (int i = 0; i < MAX; i++) dis[i] = 0x7FFFFFFF;
    dis[s] = 0;
    que.push(make_pair(dis[s], s));
    while (!que.empty()) {
        pair<int, int> u = que.top();
        que.pop();
        if (dis[u.second] < u.first) continue;
        for (int i = h[u.second]; i; i = nxt[i]) {
            if (dis[to[i]] > dis[u.second] + co[i]) {
                dis[to[i]] = dis[u.second] + co[i];
                que.push(make_pair(dis[to[i]], to[i]));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, 0, sizeof(h));
    int u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        insert(u, v, c);
    }
    int x;
    cin >> x;
    dij(x);
    for (int i = 1; i <= n; i++) {
        if (dis[i] > 100000) cout << "none" << " ";
        else cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}