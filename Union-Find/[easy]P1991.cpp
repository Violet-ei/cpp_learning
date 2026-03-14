#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
using i64 = long long;

struct node {
    int x, y;
};
struct edge {
    int u, v;
    double d;
    bool operator < (const edge &b) const {
        return d < b.d;
    }
};
double dis(node a, node b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int fa[501];
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
    int s, p;
    cin >> s >> p;
    for (int i = 1; i <= p; i++)
        fa[i] = i;
    vector<node> a(p + 1);
    vector<edge> e;
    for (int i = 1; i <= p; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= p; i++)
        for (int j = i + 1; j <= p; j++)
            e.push_back({i, j, dis(a[i], a[j])});
    sort(e.begin(), e.end());
    int cnt = p;
    for (edge i: e) {
        int u = i.u, v = i.v;
        int fu = find(u), fv = find(v);
        if (fu == fv)
            continue;
        fa[fu] = fv;
        cnt--;
        if (cnt == s) {
            printf("%.2lf\n", i.d);
            return;
        }
    }
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