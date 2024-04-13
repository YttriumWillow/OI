#include <iostream>
#include <algorithm>
#include <map>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int n, a, b;
int spc_, spc0;
i64 res;
std::map<std::pair<int, int>, int> k;

int main(/*int argc, char const* argv[]*/) {
    file("shooting");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> a >> b;
    while (n--) {
        int x0, y0;
        std::cin >> x0 >> y0;

        if (x0 - a == 0) { ++spc_; }
        else if (y0 - b == 0) { ++spc0; }
        else {
            int dy = (y0 - b), dx = (x0 - a);
            int g = std::__gcd(abs(dy), abs(dx));
            dy /= g, dx /= g;
            if (dy * dx < 0) {
                ++k[{-abs(dy), abs(dx)}];
            } else {
                ++k[{ abs(dy), abs(dx)}];
            }
        }
    }

    for (auto P : k) {
        if (P.second > 1) {
            res += 1ll * P.second * (P.second - 1);
        }
    }
    if (spc0 > 1) res += 1ll * spc0 * (spc0 - 1);
    if (spc_ > 1) res += 1ll * spc_ * (spc_ - 1);

    std::cout << res << '\n';
}