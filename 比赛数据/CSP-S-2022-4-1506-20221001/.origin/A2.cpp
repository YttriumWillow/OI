#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, Q;
int check(int x) {
    int d = 1, cnt = 0;
    while (d <= x) {
        int t = x / d, s = x / t;
        cnt += min(m, t) * (s - d + 1);
        d = s + 1;
    }
    return cnt;
}
signed main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    cin >> n >> m >> Q;
    while (Q--) {
        int k;
        cin >> k;
        int l = 1, r = k;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        cout << l << endl;
    }
    return 0;
}