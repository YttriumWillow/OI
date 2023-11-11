#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

const int N = 1e6 + 10;

int n, a[N]; i64 res;
__gnu_pbds::priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	rep (i, 1, n)
	{
		int x; cin >> x; x -= i;
		if (!q.empty() and q.top() > x)
			res += q.top() - x, q.pop(), q.push(x);
		q.push(x); a[i] = q.top();
	}

	per (i, n - 1, 1) a[i] = min(a[i], a[i + 1]);

	cout << res << endl;

	rep (i, 1, n)
		cout << a[i] + i << " \n"[i == n];

	return 0;
}