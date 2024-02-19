#include <iostream>

#include <set>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int K = 6;

int n, m;
int a[N][K];
int f[N][K];
int g[N][K];

namespace Sol
{
inline void Special()
{
	for (int i = 1; i <= n; ++i)
		cout << 1 << ' ';
	exit(0);
}
inline void Subtask1()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 1; k <= m; ++k)
		{
			if (a[i][k] > f[i - 1][k])
			{
				f[i][k] = a[i][k];
				g[i][k] = i;
			}
			else
			{
				f[i][k] = f[i - 1][k];
				g[i][k] = g[i - 1][k];
			}
		}
		set<int> s;
		for (int k = 1; k <= m; ++k)
			s.insert(g[i][k]);
		cout << s.size() << ' ';
	}
}
}

int main()
{
	freopen("s.in", "r", stdin);
	freopen("s.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	if (m == 1) Sol::Special();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	Sol::Subtask1();
	return 0;
}