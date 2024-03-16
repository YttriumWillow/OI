#include <iostream>
#include <queue>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 510;

int n, m, A[N], B[N];
int G[N][N], vis[N];

namespace Sol {
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	rep (v, 1, n) if (G[u][v]) dfs(v);
}
void sol() {
	std::cin >> n >> m;

	rep (i, 1, n) { std::cin >> A[i]; }
	rep (i, 1, n) { std::cin >> B[i]; }
	rep (i, 1, n) { vis[i] = 0; }

	rep (i, 1, n) rep (j, 1, i) {
		if (A[i] == A[j] or (A[i] - A[j]) * (B[i] - B[j]) < 0) {
			G[i][j] = G[j][i] = 1;
		} else {
			G[i][j] = G[j][i] = 0;
		}
	}

	dfs(m);

	int res = 0;
	rep (i, 1, n) if (vis[i]) ++res;

	std::cout << res << '\n';
}
}

int main(/*int argc, char const *argv[]*/) {
	file("animal");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;
	while (T--) { Sol::sol(); }

	return 0;
}
