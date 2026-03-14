#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using i64 = long long;

const int N = 1001;
int fa[2 * N];
int find(int u) {
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
        return;
    fa[u] = v;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        fa[i] = i;
    while (m--) {
        char ch;
        int u, v;
        cin >> ch >> u >> v;
        if (ch == 'E')
            merge(n + v, u), merge(u + n, v);
        else
            merge(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (fa[i] == i)
            ans++;
    cout << ans << '\n';
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