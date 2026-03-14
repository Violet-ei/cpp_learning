#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1), s(2 * n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[n + i] = a[i];
    for (int i = 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + a[i];
    vector<int> q(2 * n + 1), pos(2 * n + 1);
    int head = 1, tail = 0, ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        while (head <= tail && q[tail] >= s[i])
            tail--;
        q[++tail] = s[i];
        pos[tail] = i;
        if (head <= tail && i - pos[head] >= n)
            head++;
        if (n < i && i <= 2 * n && s[i - n] <= q[head])
            ans++;
    }
    cout << ans << '\n';
}

void solve2() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    // start from k
    // right: min(s_i - s_{k - 1})
    // left:  min(s_n - s_{k - 1} + s_{i - 1})
    vector<int> minle(n + 1), minri(n + 1);
    minle[1] = s[1];
    for (int i = 2; i <= n; i++)
        minle[i] = min(minle[i - 1], s[i]);
    minri[n] = s[n];
    for (int i = n - 1; i >= 1; i--)
        minri[i] = min(minri[i + 1], s[i]);
    int ans = 0;
    for (int k = 1; k <= n; k++)
        if (minri[k] >= s[k - 1] && s[n] - s[k - 1] + minle[k - 1] >= 0)
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