#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

i64 n, m, k, t;
std::vector<i64> A;

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m >> k >> t;

    rep (i, 1, n) rep (j, 1, m) {
        int v; std::cin >> v;
        A.push_back(v);
    }

    std::sort(A.begin(), A.end(), std::greater<int>());

    i64 cnt = 0;
    i64 res = 0;

    for (auto v : A) {
        if (cnt > k) { t += cnt / k; cnt %= k; }
        if (t <= 0) { break; }
        if (t > 0) { cnt += v; res += v; --t; }
    }

    std::cout << res << '\n';

}