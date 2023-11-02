#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;

int n, m, l, r;
string s;
i64 X, Y;
i64 cntw, cnta, cnts, cntd;
int sumw[N], suma[N], sums[N], sumd[N];

int main()
{
	file("move");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> s; s = '#' + s;

	rep (i, 1, n)
	{
		sumw[i] = sumw[i - 1] + (s[i] == 'W');
		suma[i] = suma[i - 1] + (s[i] == 'A');
		sums[i] = sums[i - 1] + (s[i] == 'S');
		sumd[i] = sumd[i - 1] + (s[i] == 'D');
	}

	rep (i, 1, m)
	{
		cin >> l >> r;

		cntw = sumw[r] - sumw[l - 1];
		cnta = suma[r] - suma[l - 1];
		cnts = sums[r] - sums[l - 1];
		cntd = sumd[r] - sumd[l - 1];

		abs(X + cntd) >= abs(X - cnta) ? X += cntd : X -= cnta;
		abs(Y + cntw) >= abs(Y - cnts) ? Y += cntw : Y -= cnts;
	}

	cout << X << ' ' << Y << endl;

	return 0;
}