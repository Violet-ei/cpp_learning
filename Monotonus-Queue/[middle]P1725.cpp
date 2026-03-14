#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using i64 = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    int m = r - l + 1;

    vector<int> a(n + 1), q(n + 1), pos(n + 1);
    vector<int> dp(n + 1, -0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 0; i <= n; i++)
        cin >> a[i];
    int head = 1, tail = 0;
    int ans = -0x3f3f3f3f;

    // dp[i] = max(dp[j]) + a[i], j in [i - r, i - l]
    // dp[i + l] = max(dp[j]) + a[i + l], j in [i - (r - l), i]
    // unreachable dp[i] can not enter the queue

    for (int i = 0; i <= n - l; i++) {
        if (dp[i] > -0x3f3f3f3f) {
            while (head <= tail && q[tail] <= dp[i])
                tail--;
            q[++tail] = dp[i];
            pos[tail] = i;
        }
        if (i - pos[head] >= m)
            head++;
        if (head <= tail)
            dp[i + l] = q[head] + a[i + l];
    }
    for (int i = n - r + 1; i <= n; i++)
        ans = max(ans, dp[i]);
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