#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e3 + 10;
const int M = 1e6 + 10;

int n, m, cnt;
int a[N], d[M], res[M];
int rem = 0;
vector<int> c;

int main()
{
	file("div");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, m) cin >> a[i]; 
	rep (i, 1, m)
		for (int j = 1; j * j <= a[i]; ++j)
		{
			if (!(a[i] % j) and j <= n)
			{
				d[++cnt] = j;
				if ((a[i] / j) != j && (a[i] / j) <= n) d[++cnt] = (a[i] / j);
			}
		}
	sort(d + 1, d + cnt + 1);

	int siz = 1; d[cnt + 1] = d[cnt] ^ 1;
	rep (i, 1, cnt)
	{
		if (d[i] == d[i + 1]) ++siz;
		else c.push_back(siz), siz = 1;
	}

	rep (i, 1, m)
	{
		for (auto v : c)
			if (v == i) ++res[i];
		rem += res[i];
	}

	cout << n - rem << endl;
	rep (i, 1, m)
		cout << res[i] << endl;

	return 0;
}