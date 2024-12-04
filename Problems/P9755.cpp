#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e5 + 5;

int n, m, k;
int a[N], b[N], c[N];
std::vector<int> G[N];

int main(/*int argc, char const* argv[]*/) {
	sync(false, nullptr);
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i] >> b[i] >> c[i];
	rep (i, 2, n) {
		int u, v; std::cin >> u >>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	

}