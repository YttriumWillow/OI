#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;

char ch;
int n, m, cnt;
bool a[N];
int res[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> ch; a[i] = (ch == 'N');

		cnt += a[i];
		if (a[i]) res[i] = cnt;
		else res[i] = 1;

		if (i == 1 && a[i] == 0) { cout << "No solution" << endl, exit(0); }
		if (cnt > n) { cout << "No solution" << endl, exit(0); }
	}
	for (int i = 1; i <= m; ++i)
		cout << res[i] << ' ';
	return 0;
}