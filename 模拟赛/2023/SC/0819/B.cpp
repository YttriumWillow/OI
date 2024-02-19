#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define prob "change"

using namespace std;

const int N = 3e5 + 10;

int n, res;
int a[N], buc[N];
int p, q, ed;

int main()
{
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	// the res is the number of in the string 0 except the last several ones.

	q = n;
	for (int i = 1; i <= n; ++i)
	{ cin >> a[i];

		buc[a[i]] = 1; ++res;

		while (buc[q] == 1) --q, --res;

		cout << res << ' ';
	}
	return 0;
}

