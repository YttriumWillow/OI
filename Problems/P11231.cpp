#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 1e5 + 5;
int n, buc[N], a[N], res;

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> a[i]; ++buc[a[i]];
    }
    rep (i, 1, n) {
        res = std::max(res, buc[i]);
    }
    std::cout << res << '\n';
}