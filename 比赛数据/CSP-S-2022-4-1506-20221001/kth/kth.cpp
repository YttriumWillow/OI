#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, q;
bool check(int x) {
    int res = 0;
    int t = sqrt(x);
    for (int i = 1; i <= t && i <= n; i++) {
        res += min(m, x / i);
    }
    for (int i = 1; i <= x / (t + 1) && i <= m; i++) {
        res += max(0ll, min(n - t, x / i - t));
    }
    if (res >= k)
        return true;
    return false;
}
signed main() {
    // freopen("kth.in", "r", stdin);
    // freopen("kth.out", "w", stdout);
    cin >> n >> m >> q;
    while (q--) {
        cin >> k;
        int l = 1, r = k;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}