#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int n, cnt[3][3];

int main(/*int argc, char const* argv[]*/) {
    file("data");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) {
        int x, y;
        std::cin >> x >> y;
        if (x == 0) {
            if (y > 0) cnt[0][2]++, cnt[2][2]++;
            else cnt[0][0]++, cnt[2][0]++;
        }
        if (y == 0) {
            if (x > 0) cnt[2][0]++, cnt[2][2]++;
            else cnt[0][0]++, cnt[0][2]++;
        }
        if (x == 0 or y == 0) continue;
        cnt[1 + (x / abs(x))][1 + (y / abs(y))]++;
    }
    if ((cnt[0][0] == 0 and cnt[0][2] == 0)
        or (cnt[0][2] == 0 and cnt[2][2] == 0)
        or (cnt[2][2] == 0 and cnt[2][0] == 0)
        or (cnt[2][0] == 0 and cnt[0][0] == 0)
        )
        std::cout << "NO" << '\n';
    else std::cout << "banana" << '\n';
}