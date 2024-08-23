#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int nS, nT, pos[30];
int nxt[(int)5e5 + 5][30], res = 1;
std::string S, T;

int main(/*int argc, char const* argv[]*/) {
    file("string"); offsync();
    std::cin >> S >> T;
    nS = S.size(); S = '#' + S;
    nT = T.size(); T = '#' + T;
    for (int i = nS; i >= 1; --i) {
        pos[S[i] - 'a'] = i;
    }
    for (int i = nS; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) nxt[i][j] = pos[j];
        if (i) pos[S[i] - 'a'] = i;
    }
    int cur = 0;
    rep (i, 1, nT) {
        if (!nxt[cur][T[i] - 'a'])
            return (std::cout << -1 << '\n'), 0;
        if (nxt[cur][T[i] - 'a'] <= cur) ++res;
        cur = nxt[cur][T[i] - 'a'];
    }
    std::cout << res << '\n';
}