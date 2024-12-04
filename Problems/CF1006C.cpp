#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)


const int maxn = 2e5 + 10;
int n, x;
i64 sum[maxn], res;
int main() {
    std::cin >> n;
    rep (i, 1, n) {
        int x; std::cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    for (int i = 1; i <= n; i++)
        if (sum[i] <= sum[n] / 2) {
            int x = std::lower_bound(sum + 1, sum + n + 1, sum[n] - sum[i]) - sum;
            if (x >= i && sum[x] == sum[n] - sum[i])
                res = sum[i];
        }
    std::cout << res << '\n';
}