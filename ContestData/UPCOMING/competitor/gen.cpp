#include <iostream>
#include "testlib.h"

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>("n");
    int v = opt<int>("v");

    int lmt1 = v - rnd.next((int)sqrt(v));
    int lmt2 = v - rnd.next((int)sqrt(v));
    int lmt3 = v - rnd.next((int)sqrt(v));
    
    std::cout << n << '\n';

    rep (i, 1, n) {
        std::cout << rnd.next(0, lmt1) << ' ';
        std::cout << rnd.next(0, lmt2) << ' ';
        std::cout << rnd.next(0, lmt3) << '\n';
    }

    std::cout << 

}