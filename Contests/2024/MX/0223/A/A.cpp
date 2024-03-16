#include <iostream>
#include <queue>

#define i64 long long 
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

int n, m, c[2]; i64 res;
std::priority_queue<int> Q[2];

int main(/*int argc, char const *argv[]*/)
{
	file("genshin");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m;
	
	rep (i, 1, n) {
		int tp, v;
		std::cin >> tp >> v;
		Q[tp].push(v);
	}

	c[0] = m; c[1] = n - m;

	while (!Q[0].empty() && c[1]) {
		res += 1ll * Q[0].top() + 1ll * Q[0].top() / 2ll; --c[1];
		Q[0].pop();
	}

	while (!Q[1].empty() && c[0]) {
		res += 2ll * Q[1].top(); --c[0];
		Q[1].pop();
	}


	while (!Q[0].empty() && c[0]) {
		res += 1ll * Q[0].top(); --c[0];
		Q[0].pop();
	}

	while (!Q[1].empty() && c[1]) {
		res += 1ll * Q[1].top(); --c[1];
		Q[1].pop();
	}

	std::cout << res << '\n';

	return 0;
}
