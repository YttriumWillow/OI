#include <iostream>
#include <cstring>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, tot;
i64 res;
string s;

int main()
{
	freopen("bamboo.in", "r", stdin);
	freopen("bamboo.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> s; s = '#' + s;
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == ')')
			++tot;
		if (s[i] == '(')
		{
			if (tot >= 0)
				res += tot;
			--tot;
		}
	}
	cout << res << endl;
	return 0;
}