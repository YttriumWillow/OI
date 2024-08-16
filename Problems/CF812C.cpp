#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e5 + 10;

int n, S, a[N], v[N];

bool check(int c) {
    rep (i, 1, n) v[i] = a[i] * c;
    std::sort(v + 1, v + n + 1);
    int cnt = 1, val = 0;
    while (cnt <= n and val <= S)
        val += v[cnt++];
    return val <= S and cnt >= c;
}

int main() {
    std::cin >> n >> S;
    rep (i, 1, n) std::cin >> a[i];

    std::cerr << (8 % (-6)) << ' ' << ((-8) % (6));

    int l = 0, r = n;

    while (l < r) {
        int mid = l + r >> 1;
        check(mid) ? l = mid : r = mid - 1;
    }

    std::cout << l << '\n';

}