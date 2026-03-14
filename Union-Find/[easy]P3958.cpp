#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

int fa[1001];
struct node {
    i64 x, y, z;
};
bool dis(node a, node b, i64 r) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) <= 4 * r * r;
}
int find(int u) {
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    fa[u] = v;
}

void solve() {
    int n;
    i64 h, r;
    cin >> n >> h >> r;
    vector<node> a(n + 1);
    vector<int> dn, up;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        fa[i] = i;
        if (a[i].z <= r)
            dn.push_back(i);
        if (a[i].z + r >= h)
            up.push_back(i);
        for (int j = 1; j < i; j++)
            if (dis(a[i], a[j], r))
                merge(i, j);
    }

    for (int i: dn)
        for (int j: up)
            if (find(i) == find(j)) {
                cout << "Yes\n";
                return;
            }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}