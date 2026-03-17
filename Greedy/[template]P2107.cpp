#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using i64 = long long;
struct node {
    i64 x, t;
    bool operator < (const node &b) const {
        return x < b.x;
    }
};

void solve() {
    int n;
    i64 m, sum = 0, ans = 0;
    cin >> n >> m;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].t;
    sort(a.begin() + 1, a.end());
    priority_queue<i64> q;
    for (int i = 1; i <= n; i++) {
        sum += a[i].x - a[i - 1].x + a[i].t;
        q.push(a[i].t);
        if (sum <= m)
            ans++;
        else {
            sum -= q.top();
            q.pop();
        }
    }
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