#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e5 + 10;

int n, a[N]; i64 sum;

int main(/*int argc, char const* argv[]*/) {
    // file("stone");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }

    std::sort(a + 1, a + n + 1);

    rep (i, 1, n) {
        if (a[i] <= sum + 1) {
            sum += a[i];
        } else { break ;}
    }

    std::cout << sum + 1 << '\n';

}