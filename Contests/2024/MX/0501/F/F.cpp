#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e3 + 10;

int n, a[N]; i64 res;

namespace Sol {
    void subtask1() {
        std::cout << a[1] << '\n';
    }
    void subtask2() {
        std::cout << 0 << '\n';
    }
    void subtask3() {
        i64 r1 = 0, r2 = 0;
        rep (i, 1, n) {
            r1 += r1 + a[i];
        }
        rep (i, n + 1, n << 1) {
            r2 += r2 + a[i];
        }
        std::cout << r2 - r1 << '\n';
    }
}

int main(/*int argc, char const* argv[]*/) {
    file("four");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    bool f2 = 1, f3 = 1;
    rep (i, 1, n << 1) {
        std::cin >> a[i];
        if (a[i] != a[i - 1]) f2 = 0;
        if (a[i] > a[i - 1]) f3 = 0;
    }

    if (n == 1) return Sol::subtask1(), 0;
    if (f2) return Sol::subtask2(), 0;
    if (f3) return Sol::subtask3(), 0;

}