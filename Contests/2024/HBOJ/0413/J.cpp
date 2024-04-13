#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int n, a[N], resl, resr;
i64 sum, res = -inf;

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n;
    
    rep (i, 1, n) { std::cin >> a[i]; }

    int l = 1;
    rep (i, 1, n) {
        (sum >= 0) ? sum += a[i] : (l = i, sum = a[i]);
        if (sum > res) {
            resl = l; resr = i;
            res = sum;
        }
    }

    std::cout << resl << '\n' << resr << '\n';
    std::cout << res << '\n';
}