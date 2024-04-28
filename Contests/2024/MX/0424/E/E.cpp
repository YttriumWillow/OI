#include <iostream>
#include <vector>
#include <queue>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 3e3 + 10;

int n, m;
int s1, t1, l1;
int s2, t2, l2;
int d[N][N];
std::vector<int> G[N];

void bfs(int S, int* ds) {
    std::queue<int> Q; Q.push(S);
    std::fill(ds + 1, ds + n + 1, 0x3f3f3f3f);
    ds[S] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : G[u]) {
            if (ds[u] + 1 < ds[v]) {
                ds[v] = ds[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main(/*int argc, char const* argv[]*/) {
    file("destroy");
    
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    std::cin >> s1 >> t1 >> l1;
    std::cin >> s2 >> t2 >> l2;

    rep (i, 1, n) { bfs(i, d[i]); }

    if (d[s1][t1] > l1 || d[s2][t2] > l2) {
        std::cout << -1 << '\n';
        return 0;
    }

    int Min, dA, dB, dC, dD;
    int res = d[s1][t1] + d[s2][t2];

    rep (i, 1, n) {
        rep (j, i + 1, n) {
            Min = d[i][j];
            dA = std::min(d[s1][i], d[s1][j]);
            dB = std::min(d[t1][i], d[t1][j]);
            dC = std::min(d[s2][i], d[s2][j]);
            dD = std::min(d[t2][i], d[t2][j]);
            if (dA + dB + Min > l1 || dC + dD + Min > l2) continue;
            res = std::min(res, dA + dB + dC + dD + Min);
        }
    }

    std::cout << m - res << '\n';

}