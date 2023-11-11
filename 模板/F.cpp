#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 2e3 + 10;

int n, m;
int a[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	rep (i, 1, 2 * n) rep (j, 1, 2 * m)
	{
		cin >> a[i][j];
	}

	rep (i, 1, 2 * n) rep (j, 1, 2 * m)
	{
		if (i & 1)
		{
			a[i][j] += a[i][j + 1];
		}	
	}

	rep (i, 1, 2 * n) rep (j, 1, 2 * m)
	{
		if (j & 1)
		{
			a[i][j] += a[i + 1][j];
		}
	}

	rep (j, 1, 2 * m) rep (i, 1, 2 * n)
	{
		if ((i & 1) and (j & 1))
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}


	return 0;
}