#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> fa(n + 1), siz(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i, siz[i] = 1;

    auto find = [&](auto&& find, int u) -> int {
        if (fa[u] == u)
            return u;
        return fa[u] = find(find, fa[u]);
    };
    auto merge = [&](int u, int v) -> void {
        u = find(find, u), v = find(find, v);
        if (u == v)
            return;
        if (siz[u] > siz[v])
            swap(u, v);
        else if (siz[u] == siz[v])
            siz[v]++;
        fa[u] = v;
    };

    int u, v;
    while (m--) {
        cin >> u >> v;
        merge(u, v);
    }
    while (p--) {
        cin >> u >> v;
        if (find(find, u) == find(find, v))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}