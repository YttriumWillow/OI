#include <iostream>
#include <queue>

#define i64 long long 
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 1e5 + 10;

int n, m, A[N], B[N];
i64 res;

int main(/*int argc, char const *argv[]*/)
{
	file("square");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m;
	
	rep (i, 1, n) { std::cin >> A[i]; }
	rep (i, 1, m) { std::cin >> B[i]; }

	rep (i, 2, n) { res += llabs(A[i] - A[i - 1]); }
	rep (i, 2, m) { res += llabs(B[i] - B[i - 1]); }

 	std::cout << res << '\n';

	return 0;
}
