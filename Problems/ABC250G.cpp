#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int n, x; i64 res;
__gnu_pbds::priority_queue<int, greater<int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		cin >> x;
		if (!q.empty() && q.top() < x)
			res += x - q.top(), q.pop(), q.push(x);
		q.push(x);
	}
	cout << res << endl;
	return 0;
}