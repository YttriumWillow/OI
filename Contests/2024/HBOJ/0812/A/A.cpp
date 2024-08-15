#include <iostream>
#include <algorithm>
#include <functional>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e6 + 5;

int n, k, p[N], d[N], a[N];

int main(/*int argc, char const* argv[]*/) {
    file("ball");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> k;
    rep (i, 1, n) {
        int v; std::cin >> v;
        p[v] = i;
    }
    rep (i, 2, n) {
        int u = p[i - 1], v = p[i];
        if (u > v) std::swap(u, v);
        ++d[u]; --d[v];
    }
    rep (i, 1, n) {
        a[i] = a[i - 1] + d[i];
    }

    std::sort(a + 1, a + n, std::greater<int>());

    // rep (i, 1, n) {
    //     std::cerr << a[i] << " \n"[i == n];
    // }

    int sum = 0, res = 0;

    rep (i, 1, n - 1) if (sum < k) {
        sum += a[i]; ++res;
    }

    std::cout << (sum >= k ? res : -1) << '\n';

}