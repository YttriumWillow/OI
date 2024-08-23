#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e6 + 10;

int n, res, a[N]; bool r[N];
int max[N], min[N], odv[N];

void solve() {
    std::cin >> n; res = 0; min[0] = n;
    rep (i, 1, n) {
        std::cin >> a[i]; r[i] = 0;
        max[i] = std::max(max[i - 1], a[i]);
        min[i] = std::min(min[i - 1], a[i]);
        odv[i] = i == 1 ? 1 : odv[i - 1] & !((a[i] ^ a[1]) & 1);
    }
    if (a[1] == 1 or a[1] == n)  r[1] = 1;
    if (a[n] == 1 or a[n] == n)  r[n - 1] = 1;

    if (
        a[1] == 1 and a[2] == n
     or a[1] == n and a[2] == 1
    ) r[2] = 1;
    if (
        a[n - 1] == 1 and a[n] == n
     or a[n - 1] == n and a[n] == 1
    ) r[n - 2] = 1;

    if (
        !(n & 1) and odv[n >> 1]
      or (n & 1) and (odv[n >> 1] and !(a[1] & 1) )
    ) r[n >> 1] = 1;
    if ((n & 1) and (odv[(n >> 1) + 1]))  r[(n >> 1) + 1] = 1;

    rep (i, 2, n - 2) if (max[i] == i || min[i] == n - i + 1) r[i] = 1;
    rep (i, 1, n - 1) if (r[i]) ++res;
    std::cout << res << '\n';
}
void f() {
    return void();
}
int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
}