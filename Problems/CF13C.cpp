#include <iostream>
#include <queue>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 5e5 + 10;

priority_queue<int> q;
int n; i64 a[N], res;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		cin >> a[i]; q.push(a[i]);
		if (a[i] < q.top())
			res += q.top() - a[i], q.pop(), q.push(a[i]);
	}

	cout << res << endl;

	return 0;
}