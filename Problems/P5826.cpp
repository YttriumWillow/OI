#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;
constexpr int V = 105;

int t, n, q, m;
int a[N], b[N];

class SeqAutomation {
    static constexpr int N = ::N;
    static constexpr int V = ::V;
public:
    int n, nxt[N][V];
    SeqAutomation(int* a, int _n, int r) {
        n = _n;
        for (int i = n; i; --i) {
            rep (j, 1, r) nxt[i - 1][j] = nxt[i][j];
            nxt[i - 1][a[i]] = i;
        }
    }
};

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> t >> n >> q >> m;
    assert(t <= 2);
    rep (i, 1, n) std::cin >> a[i];
    SeqAutomation SA(a, n, m);
    while (q--) {
        int k, st = 0, res = 0; std::cin >> k;
        rep (j, 1, k) {
            int f; std::cin >> f;
            st = SA.nxt[st][f];
            if (!st) {
                while (j < k) { ++j; std::cin >> t; }
                res = 1;
            }
        }
        std::cout << (res ? "No" : "Yes") << '\n';
    }
}