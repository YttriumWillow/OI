#include <iostream>
#include <queue>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define x first
#define y second

using namespace std;

const int N = 4e5 + 10;
const int inf = 0x3f3f3f3f;

int n, k, res, tot;
int ava[N]; bool v[N];
pair<int, int> a[N];
priority_queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	rep (i, 1, n) cin >> a[i].x;

	per (i, n, 1)
	{
		if (!ava[a[i].x])
			a[i].y = inf;
		else
			a[i].y = ava[a[i].x];

		ava[a[i].x] = i;
	}

	rep (i, 1, n)
	{
		if (!v[a[i].x])
		{
			++res, ++tot;
			if (tot > k)
			{
				--tot; auto u = q.top(); q.pop();
				v[a[u.y].x] = 0;
			}
			v[a[i].x] = 1;
		}
		q.push({ a[i].y, i });
	}

	cout << res << endl;

	return 0;
}