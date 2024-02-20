#include <iostream>
#include <algorithm>

using namespace std;

template<typename Tp>
struct PairingHeap
{
	Tp val[N];
	vector<int> G[N];
	inline void add(int u, int v) { g[u].push_back(v); }
	inline int merge(int u, int v)
	{
		if (!u) return v;
		if (!v) return u;
		if (val[u] < val)
	}
	inline int fpop(int u)
	{
		if (!u) return v;
		if (!v) return u;
	}
	inline void dfs(int u)
	{
		res[++tot] = val[u];
		for (auto v : G[u]) dfs(v);
	}
	inline void push(const Tp& x)
	{

	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	return 0;
}