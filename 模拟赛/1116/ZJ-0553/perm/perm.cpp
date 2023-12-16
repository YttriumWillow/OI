#include <iostream>
#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 3e5 + 10;

int n, p[N], q[N], a[N];
bool tag[N];

int main()
{
	file("perm");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) cin >> p[i];
	rep (i, 1, n) cin >> q[i];

	rep (i, 0, n - 1)
	{
		tag[q[i]] = 1;
		priority_queue<int> Q;
		rep (j, 1, n)
		{
			Q.push(p[j]);
			if (tag[j]) Q.pop();	
		}
		cout << Q.top() << ' ';
	}
	return 0;
}