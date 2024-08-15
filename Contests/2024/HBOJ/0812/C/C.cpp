#include <iostream>
#include <set>
#include <map>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 5;

typedef std::pair<int, int> Pii;

int n;
struct comp {
    bool operator() (const Pii& A, const Pii& B) {
        return A.first > B.first;
    }
};
std::set<Pii, comp> M1, M2;

int main(/*int argc, char const* argv[]*/) {
    file("pairs");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) {
        int x, y; std::cin >> x >> y;
        M1.insert({ x, y });
        M2.insert({ y, x });
    }

    i64 res = 0;

    while (!M1.empty()) {
        auto P1 = *M1.begin();
        int vx = P1.first; // (x, y)
        auto P2 = *M2.begin();
        int vy = P2.first; // (y, x)

        if (vx < vy) {
            M2.erase(M2.lower_bound({ P1.second,0 }));
            M1.erase(M1.begin());
            res += vx;
        }
        else {
            M1.erase(M1.lower_bound({ P2.second,0 }));
            M2.erase(M2.begin());
            res += vy;
        }
    }

    std::cout << res << '\n';

}