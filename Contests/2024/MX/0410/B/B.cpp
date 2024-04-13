#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 5e5 + 10;

i64 n, Q, a[N];

int main(/*int argc, char const* argv[]*/) {
    file("double");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> Q;

    rep (i, 1, n) std::cin >> a[i];


    while (Q--) {
        i64 k, x; std::cin >> k >> x;

        int pos = std::lower_bound(a + 1, a + n + 1, x) - a;
        i64 l = a[pos - 1], r = a[pos], cnt = 0;

        if (a[pos] == x) { std::cout << "Yes\n"; continue; }
        if (x < a[pos] and pos == 1) { std::cout << "No\n"; continue; }
        if (x > a[pos] and pos == n) { std::cout << "No\n"; continue; }

        while (l < r) {
            i64 mid = (l + r) >> 1; ++cnt;
            if (mid == x) { break; }
            (x < mid) ? r = mid : l = mid;
        }

        std::cout << (cnt <= k ? "Yes" : "No") << '\n';
    }

}