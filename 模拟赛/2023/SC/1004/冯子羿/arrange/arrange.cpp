#include <iostream>

#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 5e5 + 10;

#define fix(x) (((x - 1) % n + n) % n + 1)

int n, m, l, r;
int a[N], pos[N];
i64 res;

inline void move(int d)
{
	res += abs(d); l += d; r += d; l = fix(l); r = fix(r);
	// cerr << "to: " << l << ' ' << r << endl; 
}

int main()
{
	file("arrange");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; 
	for (int i = 1; i <= n; ++i)
		cin >> a[i], pos[a[i]] = i;

	if (m == n) { cout << 0 << endl, exit(0); }

	l = 1, r = m;

	for (int i = 1; i <= n; ++i)
	{
		// cerr << "loc: " << i << endl;
		int &p = pos[i];

		// 目前窗口 : l - r (1 <= l, r <= n)
		// 目标 : p (1 <= p <= n)

		if (l <= r)
		{
			if (p <= l)
			{
				int dl = l - p;
				int dr = n + p - r;
				if (dl < dr) move(-dl);
				else move(dr);
			}
			else
			{
				if (p <= r) continue;
				int dr = p - r;
				int dl = n + l - p;
				if (dl < dr) move(-dl);
				else move(dr);				
			}
		}

		if (l > r)
		{
			if (p <= l)
			{
				if (p <= r) continue;
				int dl = l - p;
				int dr = p - r;
				if (dl < dr) move(-dl);
				else move(dr);	
			}
			else
			{
				continue;
			}
		}
		// cerr << endl;
	}

	cout << res << endl;

	return 0;
}