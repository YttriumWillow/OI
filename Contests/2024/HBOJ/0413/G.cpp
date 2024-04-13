#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 1e5 + 10;
int n, a[N], res;

namespace BIT {
    int t[N] = { 0 };
    #define lowbit(x) ((x) & (-x))
    void add(int x, int k) {
        for (int i = x; i <= n + 5; i += lowbit(i))
            t[i] += k;
    }
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += t[i];
        return res;
    }
}

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n;

    rep (i, 1, n) {
        int x; std::cin >> x; x = n + 1 - x;
        res += BIT::query(x - 1);
        BIT::add(x, 1);
    }

    std::cout << res << '\n';
}