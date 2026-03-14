#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

const int N = 10001;
int fa[N][2], siz[N][2];
int find(int u, int r) {
    if (fa[u][r] == u)
        return u;
    return fa[u][r] = find(fa[u][r], r);
}
void merge(int u, int v, int r) {
    u = find(u, r), v = find(v, r);
    if (u == v)
        return;
    fa[u][r] = v;
    siz[v][r] += siz[u][r];
}

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= max(n, m); i++)
        for (int r = 0; r <= 1; r++)
            fa[i][r] = i, siz[i][r] = 1;
    while (p--) {
        int u, v;
        cin >> u >> v;
        merge(u, v, 0);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        merge(-u, -v, 1);
    }
    cout << min(siz[find(1, 0)][0], siz[find(1, 1)][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}