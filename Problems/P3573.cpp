#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 5e5 + 10;

int n, m, res, www;
class XHG {
    std::multiset<int, std::greater<int>> S;
public:
    void insert(int v) { S.insert(v); }
    void remove(int v) {
        auto pos = S.find(v);
        if (pos != S.end()) S.erase(pos);
    }
    int max() { return *S.begin(); }
};
XHG S; int in[N], arr[N];
std::vector<int> Gs[N]; int ds[N];
std::vector<int> Gt[N]; int dt[N];

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr); std::cin >> n >> m;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        Gs[u].push_back(v);
        Gt[v].push_back(u); ++in[v];
    }

    
    std::queue<int> Q;
    rep (i, 1, n) if (!in[i]) Q.push(i);
    for (int i = 0; !Q.empty(); ) {
        int u = Q.front(); Q.pop(); arr[++i] = u;
        for (auto v : Gs[u]) if (!(--in[v])) Q.push(v);
    }
    rep (i, 1, n) {
        int u = arr[i];
        for (auto v : Gs[u])
            dt[v] = std::max(dt[v], dt[u] + 1);
    }
    for (int i = n; i; --i) {
        int u = arr[i];
        for (auto v : Gt[u])
            ds[v] = std::max(ds[v], ds[u] + 1);
    }



    rep (i, 1, n) S.insert(ds[i]);
    res = S.max();
    rep (i, 1, n) {
        int u = arr[i]; S.remove(ds[u]);
        for (auto v : Gt[u]) S.remove(ds[u] + dt[v] + 1);
        int _ = S.max();
        if (_ <= res) { res = _, www = u; }
        for (auto v : Gs[u]) S.insert(ds[v] + dt[u] + 1);
        S.insert(dt[u]);
    }
    std::cout << www << ' ' << res << '\n';
}