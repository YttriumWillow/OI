// Problem:      P1298 最接近的分数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1298
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-06 08:09:14 

#include <iostream>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for(int i = l; i <= (r); ++i)
#define qwq puts("fzy qwq ~");
#define dif(q) abs(q-R)

constexpr double eps = 1e-13;
constexpr double F = 1.00000000;

int m, n; double r; bool fg;

int main(/*int argc, char const* argv[]*/) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	
	std::cin >> m >> n >> r;

	int a = 0, b = 1, c = 1, d = 0, resu = 0, resv = 1;
	double dif = r; 

	while (true) {
		int e = a + c;
		int f = b + d;
		if (e > m or f > n) break;
		double v = F * e / f - r;
		if (std::fabs(v) == dif) {
			fg = 1;
		}
		if (std::fabs(v) < dif) {
			resu = e, resv = f;
			dif = std::fabs(v); fg = 0;
			if (dif == 0) break;
		}
		(v < 0) ? (a = e, b = f) : (c = e, d = f);
	}

	if (fg) std::cout << "TOO MANY" << '\n';
	else std::cout << resu << '/' << resv << '\n';
}