#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);
#define upd(v) res=std::min(res, (v));

constexpr int N = 2e5 + 5;
int n; char S[N], T[] = "#noip";

bool request(char ch) {
    rep (i, 1, 4) { if (T[i] == ch) return i; } return 0;
}

bool valid(int x, int p) {
    int i = 1, j = x;
    while (i <= 4) {
        if (j == p) ++j;
        else if (T[i] ^ S[j]) return 0;
        else ++i, ++j;
    } return 1;
}

int insert(int x, int p, int q) { // statements
    int i = 1, j = x;
    while (i <= 4) {
        if (i == p or i == q) ++i;
        else if (T[i] ^ S[j]) return 4;
        else ++i, ++j;
    } return (p and q) ? 2 : 1;
}

void solve() {
    int res = 4;
    std::cin >> (S + 6); n = strlen(S + 6);
    rep (i, 1, n + 10) if (not request(S[i])) S[i] = '*';
    rep (i, 1, n + 5) if (valid(i, 0)) { res = 0; goto fixed; }
    rep (i, 1, n + 5) {
        rep (j, i + 1, i + 3) if (valid(i, j)) upd(1);
        rep (j, i + 1, i + 3) {
            std::swap(S[j - 1], S[j]);
            if (valid(i, 0)) upd(1);
            std::swap(S[j - 1], S[j]);
        }
        rep (j, i, i + 3) {
            char ch = S[j];
            rep (k, 1, 4) {
                S[j] = T[k];
                if (valid(i, j)) upd(1);
                rep (l, 1, 4) upd(insert(i, l, 0) + 1);
            }
            S[j] = ch;
        }
        rep (j, 1, 4) rep (k, 0, 4) if (j ^ k)
            upd(insert(i, j, k));
        int cnt = 0; rep (j, i, i + 3) if (T[j - i + 1] ^ S[j])
            ++cnt;
        upd(cnt);
    }
fixed: std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    file("noip");
    offsync(); // md 怎么撞我字符串名字啊
    int Tc; std::cin >> Tc;
    while (Tc--) solve();
}