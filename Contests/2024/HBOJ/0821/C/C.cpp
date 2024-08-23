#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 3e3 + 5;
typedef std::pair<int, int> Pii;
int n, pos, S[N], T[N]; std::vector<Pii> res;

void resort(int l, int r) {
    std::vector<int> L, R; int len = r - l + 1;
    rep (i, 0, len / 2 - 1)   L.push_back(T[l + i]);
    rep (j, len / 2, len - 1) R.push_back(T[l + j]);
    int op = 0, il = 0, ir = 0; rep (i, l, r) {
        (op ^= 1) ? (T[i] = R[ir++]) : (T[i] = L[il++]);
    }
    res.push_back({ l, r });
}
int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> n;
    rep (i, 1, n) std::cin >> S[i], T[i] = i;
    resort(1, n);
    rep (i, 1, n) while (1) {
        rep (j, 1, n) if (T[j] == S[i]) { pos = j; break; }
        if (pos == i) break;
        int len = std::min(pos - i, n - pos + 1);
        resort(pos - len, pos + len - 1);
    }
    std::cout << res.size() << '\n';
    for (auto it = res.rbegin(); it != res.rend(); ++it)
        std::cout << it->first << ' ' << it->second << '\n';
}