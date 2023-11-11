#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 2e5 + 10;

int n, q, tot;
i64 res[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	rep (i, 1, n)
	{
		string eq; cin >> eq;
		i64 sgn = 1, a = 0, b = 0, c = 0, now = 0;
		for (auto ch : eq)
		{
			if (ch == 'x')
			{
				a = now * sgn;
				now = 0; sgn = 1;
				continue;
			}
			if (ch == '=')
			{
				b = now * sgn;
				now = 0; sgn = 1;
				continue;
			}
			if (ch == '+') continue;
			if (ch == '-')
			{
				sgn = -1;
			}
			else
			{
				now = now * 10 + ch - '0';
			}

		}
		c = now * sgn;

		cerr << "! : " << a << ' ' << b << ' ' << c << endl;

		res[++tot] = (c - b) / a;
	}

	sort(res + 1, res + tot + 1);
	tot = unique(res + 1, res + tot + 1) - res - 1;

	while (q--)
	{
		i64 L, R; cin >> L >> R;
		int pl = lower_bound(res + 1, res + tot + 1, L) - res;
		int pr = upper_bound(res + 1, res + tot + 1, R) - res;
		cout << pr - pl << endl;
	}

	return 0;
}