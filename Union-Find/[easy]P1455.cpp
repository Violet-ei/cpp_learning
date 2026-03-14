#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

const int N = 10001;
int fa[N];
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
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> d[i], fa[i] = i;
    while (m--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    vector<int> mon(n + 1), val(n + 1), ever(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int f = find(i);
        if (!ever[f])
            ever[f] = ++cnt;
        mon[ever[f]] += c[i];
        val[ever[f]] += d[i];
    }
    vector<int> ans(w + 1);
    for (int i = 1; i <= n; i++)
        for (int j = w; j >= mon[i]; j--)
            ans[j] = max(ans[j], ans[j - mon[i]] + val[i]);
    cout << ans[w] << '\n';
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}