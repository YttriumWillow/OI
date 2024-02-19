#include <iostream>
#include <map>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int n;
map<i64, i64> X;
map<i64, i64> Y;
map<i64, i64> Z;

inline bool prvchk()
{
	if (n % X.size()) return 0;
	if (n % Y.size()) return 0;
	if (n % Z.size()) return 0;
	return 1;
}

inline bool cntchk()
{
	i64 C = 0;

	C = n / X.size();
	for (auto P : X) if (P.second != C) return 0;
	C = n / Y.size();
	for (auto P : Y) if (P.second != C) return 0;
	C = n / Z.size();
	for (auto P : Z) if (P.second != C) return 0;

	return 1;
}

int main()
{
	file("cube");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	rep (i, 1, n)
	{
		i64 x, y, z;
		cin >> x >> y >> z;
		++X[x]; ++Y[y]; ++Z[z];
	}

	if (!prvchk()) { cout << "NO" << endl; return 0; }
	if (!cntchk()) { cout << "NO" << endl; return 0; }

	cout << "YES" << endl;

	return 0;
}