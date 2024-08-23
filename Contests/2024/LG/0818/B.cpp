#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 2e7 + 5;
constexpr int mod = 1e9 + 7;

int n, A, B, C, g[N];
bool p[N]; int cnt[N], d[N];
std::vector<int> pri;

void sieve(int n) {
    d[1] = 1;
    rep (i, 2, n) {
        if (!p[i]) pri.push_back(i), cnt[i] = 1, d[i] = 2;
        for (auto pr : pri) {
            if (pr * i > n) break;
            p[i * pr] = 1;
            if (!(i % pr)) {
                cnt[i * pr] = cnt[i] + 1;
                d[i * pr] = d[i] / cnt[i * pr] * (cnt[i * pr] + 1);
                break;
            }
            cnt[i * pr] = 1; d[i * pr] = d[i] * 2;
        }
    }
    rep (i, 1, n) d[i] = (d[i - 1] + d[i]) % mod;
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> A >> B >> C; std::cin >> g[n];

    sieve(n);

    for (int i = n - 1; i >= 1; --i)
        g[i] = ((1ll * A * g[i + 1] % mod * g[i + 1] % mod + 1ll * B * g[i + 1] % mod) % mod + C) % mod;
	int res = 0;
	rep (i, 1, n)
        res = (res + 1ll * (d[i - 1] + n) * g[i] % mod * (n - i + 1) % mod) % mod;

    std::cout << res << '\n';

}