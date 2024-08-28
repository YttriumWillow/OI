#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;

int n, m, cnt;
int dfn[N], low[N];
int h[N], tot = 1;
struct Edge { int v, w, nxt; } e[M << 1];
void add(int u, int v, int w) {
    e[++tot] = { v, w,  }
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    for (int i = h[u]; i; i = e[i].nxt) {  
                                                                                                 
    }
}

void solve() {
    std::cin >> n >> m;
    
}

int main(/*int argc, char const* argv[]*/) {
    offsync(); int T; std::cin >> T;
    while (T--) solve();
}