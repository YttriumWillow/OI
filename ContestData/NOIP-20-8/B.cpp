#include <iostream>
#include <deque>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define dis(x, y) (abs((x) - (y)))

using namespace std;

const int N = 5e5 + 10;

int n, a[N];
deque<int> q;
i64 sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n) cin >> a[i], sum += a[i];

	sort(a + 1, a + n + 1);

	rep (i, 1, n) q.push_back(a[i]);

	double L, R;
	L = R = sum * 1.0 / n;


	while (!q.empty())
	{
		int &lt = q.front();
		int &rt = q.back();

		double kl = (sum - lt) / (q.size() - 1);
		double kr = (sum - rt) / (q.size() - 1);

		if (dis())
	}

	return 0;
}