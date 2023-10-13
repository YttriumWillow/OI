#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);

	}
	return 0;
}