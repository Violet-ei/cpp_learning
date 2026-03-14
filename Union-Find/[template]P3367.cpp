#include<iostream>
using namespace std;

const int N = 200001;
int fa[N], siz[N];

int find(int u) {
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (siz[u] > siz[v])
        swap(u, v);
    else if (siz[u] == siz[v])
        siz[v]++;
    fa[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int op, u, v;
    while (m--) {
        cin >> op >> u >> v;
        if (op == 1)
            merge(u, v);
        else
            find(u) == find(v) ? cout << "Y\n" : cout << "N\n";
    }
    return 0;
}
