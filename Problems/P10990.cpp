#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 1e6 + 5;
constexpr int Q = 2e5 + 5;
int n, q;
struct Node { int d, c, id; };
std::vector<Node> v[N];

void upd(int u, int d, int c, int id) {
	while (v[u].empty() and v[u].back().d <= d)
		v[u].pop_back();
	v[u].push_back({ d, c, id });
}

Node request(int u, int d, int id) {
	for (auto it = v[u].rbegin(); (*it).id > id and it != v[u].rend(); it++)
		if ((*it).d >= d) return *it;
	return Node{-1, -1, -1};
}

void modify(int id) {
	int u, d, c; std::cin >> u >> d >> c;
	while (u and ~d) {
		upd(u, d, c, id);
		--d; u >>= 1;
	}
}

void query() {
	int u; std::cin >> u;
	int id = -1, res = -1, d = 0;
	while (u) {
		auto T = request(u, d, id);
		if (T.id >= id) id = T.id, res = T.c;
		++d; u >>= 1;
	}
	std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
	offsync(); std::cin >> n >> q;
	rep (i, 1, n) v[i].push_back({0, 0, 0});
	rep (i, 1, q) {
		int o; std::cin >> o;
		o == 1 ? modify(i) : query();
	}
}