#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node {
    long long t1, t2;
    bool operator < (const node &b) const {
        return t2 < b.t2;
    }
};
priority_queue<long long> q;
int n, ans;
long long sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i].t1 >> a[i].t2;
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++)
    {
        sum += a[i].t1;
        q.push(a[i].t1);
        if(sum <= a[i].t2)
            ans++;
        else
        {
            sum -= q.top();
            q.pop();
        }
    }
    cout << ans;
    return 0;
}