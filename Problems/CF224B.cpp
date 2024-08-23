#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;

int n, k, a[N], num[N];
int ll = -1, rr = -1;
i64 sum, cnt, res = 0x3f3f3f3f3f3f3f;

signed main() {
    offsync(); std::cin >> n >> k;
    rep (i, 1, n) std::cin >> a[i];
    int l = 1, r = 0;
    while (r < n) {
        while (r < n and cnt < k) {
            ++r; sum += a[r];
            ++num[a[r]];
            if (num[a[r]] == 1) ++cnt;
        }
        while (cnt == k) {
            if (sum < res) {
                res = sum;
                ll = l; rr = r;
            }
            sum -= a[l]; --num[a[l]];
            if (num[a[l]] == 0) --cnt;
            ++l;
        }
    }
    std::cout << ll << " " << rr << '\n';
}