#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), q(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (head <= tail && a[i] <= q[tail])
            tail--;
        q[++tail] = a[i];
        pos[tail] = i;
        if (head <= tail && i - pos[head] >= k)
            head++;
        if (i >= k)
            cout << q[head] << ' ';
    }
    cout << '\n';
    head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (head <= tail && a[i] >= q[tail])
            tail--;
        q[++tail] = a[i];
        pos[tail] = i;
        if (head <= tail && i - pos[head] >= k)
            head++;
        if (i >= k)
            cout << q[head] << ' ';
    }
    cout << '\n';
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