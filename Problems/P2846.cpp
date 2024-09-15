#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

class SGT {
    #define ls(u) ()
}

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    int n, q; std::cin >> n >> q;
    while (q--) {
        int op, l, r; std::cin >> op >> l >> r;
        if (op == 1)
            // T.modifyRev(l, r);
        else 
            std::cout << T.query(l, r) << '\n';
    }
}