#include <iostream>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define t first
#define p second

using namespace std;

const int N = 1e5 + 10;

int n, L; i64 res;
pair<int, int> v[N];
__gnu_pbds::priority_queue<int> Q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> L;
	rep (i, 1, n)
	{
		cin >> v[i].t >> v[i].p;
		v[i].t = -v[i].t; res += v[i].p;
 	}
	sort(v + 1, v + n + 1);
	rep (i, 1, n)
	{
		Q.push(-v[i].p); Q.push(-v[i].p);
		res += Q.top(); Q.pop();
	}
	cout << res << endl;

	return 0;
}