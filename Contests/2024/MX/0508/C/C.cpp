#include <iostream>
#include <cctype>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 7.5e6 + 10;

namespace IO {
#define reg register
    template<typename _Tp>
    inline void read(_Tp& x) {
        x = 0; char c = getchar(); bool f = 0;
        while (!std::isdigit(c)) f |= c == 45, c = getchar();
        while (std::isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
        return f ? x = -x : 1, void();
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
} using namespace IO;

int n, t, r, x[N];

int main(/*int argc, char const* argv[]*/) {
    file("lighthouse")

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> t >> r;
    rep (i, 1, n) { std::cin >> x[i]; }

    int lst = 1, cnt = 0, res = 0;
    rep (i, 1, n) {
        if (x[i] - r <= x[lst]) { continue; }
        else {
            res = i - 1; ++cnt; int qwq = i - 1;
            while (x[i] <= x[qwq] + r and i <= n) { res = i; ++i; }
            lst = i = res + 1;
            if (cnt >= t) { break; }
        }
    }

    if (cnt < t) { res = n; }

    std::cout << res << '\n';

}