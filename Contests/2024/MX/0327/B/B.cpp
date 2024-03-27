#include <iostream>
#include <vector>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 2e5 + 10;

int n, siz[N];
bool vis[N];
int now, Quit, resiz[N], res = 0;
std::vector<int> T[N];

void dfs(int u, int prv) {
    vis[u] = 1; siz[u] = 1;
    for (auto v : T[u]) {
        if (v == prv) continue;
        if (!vis[v]) {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
}

int cutter(int u, int prv) {
    if (Quit) return 0;
    int cnt = 0; resiz[u] = siz[u];
    for (auto v : T[u]) {
        if (v == prv) continue;

        int w = cutter(v, u);

        if (Quit) return 0;
        resiz[u] -= w; cnt += w;
        if (resiz[v] == now) {
            cnt += now;
            resiz[v] = 0;
            resiz[u] -= now;
        }
        else if (resiz[v] > now) {
            Quit = 1;
        }
    }
    return cnt;
}
void solve(int w) {
    Quit = 0; now = w;
    cutter(1, 0);
    if (!Quit) ++res;
}

int main(/*int argc, char const* argv[]*/) {
    file("eat");

    // 对于一个大小为 k 的连通块他必定是一个 siz = k 的子树。
    // 把这个子树去掉 (siz 置零) 后就有有一些子树可以按照每 k 个一刀循环剪。

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 2, n) {
        int u, v;
        std::cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    dfs(1, 0);

    rep (i, 1, sqrt(n))
        if (n % i == 0) {
            solve(i);
            if (n / i != i) {
                solve(n / i);
            }
        }

    std::cout << res << '\n';

}