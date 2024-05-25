#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

int n; std::string A, B;
int res[26], c1[26], c2[26];

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n;
    while (n--) {
        std::cin >> A >> B;
        int n1 = A.size(), n2 = B.size();
        memset(c1, 0, sizeof c1);
        memset(c2, 0, sizeof c2);
        rep (i, 0, n1 - 1) ++c1[A[i] - 'a'];
        rep (i, 0, n2 - 1) ++c2[B[i] - 'a'];
        rep (i, 0, 25) {
            c1[i] = std::max(c1[i], c2[i]);
            res[i] += c1[i];
        }
    }
    rep (i, 0, 25)
        std::cout << res[i] << '\n';
    return 0;
}