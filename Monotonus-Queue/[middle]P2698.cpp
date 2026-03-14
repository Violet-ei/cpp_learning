#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using i64 = long long;

struct node {
    int x, y;
    bool operator < (const node &b) const {
        return x < b.x;
    }
};

void solve() {
    int n, d;
    cin >> n >> d;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a.begin() + 1, a.end());
    int head1 = 1, tail1 = 0, head2 = 1, tail2 = 0;
    vector<int> q1(n + 1), p1(n + 1), q2(n + 1), p2(n + 1);
    int ans = 0x7fffffff;
    for (int l = 1, r = 1; l <= n; l++) {
        while (head1 <= tail1 && p1[head1] < l)
            head1++;
        while (head2 <= tail2 && p2[head2] < l)
            head2++;
        while (r < n) {
            if (head1 <= tail1 && head2 <= tail2 && a[p1[head1]].y - a[p2[head2]].y >= d)
                break;
            r++;
            while (head1 <= tail1 && a[p1[tail1]].y < a[r].y)
                tail1--;
            p1[++tail1] = r;
            while (head2 <= tail2 && a[p2[tail2]].y > a[r].y)
                tail2--;
            p2[++tail2] = r;
        }
        if (head1 <= tail1 && head2 <= tail2 && a[p1[head1]].y - a[p2[head2]].y >= d)
            ans = min(ans, a[r].x - a[l].x);
    }
    if (ans == 0x7fffffff)
        cout << -1 << '\n';
    else
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