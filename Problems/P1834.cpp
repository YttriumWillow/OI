#include <iostream>
#include <algorithm>
#include <functional>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int tot, a[5];
string res[N];
string sym[5] = { "#", "+", "-", "*", "/" };

function<int(int, int)> calc[5] =
{
	[](int a, int b) { return (a == inf or b == inf) ? inf : -1; },
	[](int a, int b) { return (a == inf or b == inf) ? inf : a + b; },
	[](int a, int b) { return (a == inf or b == inf) ? inf : a - b; },
	[](int a, int b) { return (a == inf or b == inf) ? inf : a * b; },
	[](int a, int b)
	{
		if (b == 0) return inf;
		if (a % b == 0) return a / b;
		return inf;
	},
};

int main()
{
	rep(i, 1, 4) cin >> a[i];
	sort(a + 1, a + 5);
	do
	{
		rep(i, 1, 4) rep(j, 1, 4) rep(k, 1, 4)
		{
			if (calc[j](calc[i](a[1], a[2]), calc[k](a[3], a[4])) == 24)
				res[++tot] += string("((") + (char)(a[1] + '0') + sym[i] + (char)(a[2] + '0') + string(")") + sym[j] + string("(") + (char)(a[3] + '0') + sym[k] + (char)(a[4] + '0') + string("))");
			if (calc[k](calc[j](calc[i](a[1], a[2]), a[3]), a[4]) == 24)
				res[++tot] += string("(((") + (char)(a[1] + '0') + sym[i] + (char)(a[2] + '0') + string(")") + sym[j] + (char)(a[3] + '0') + string(")") + sym[k] + (char)(a[4] + '0') + string(")");
			if (calc[k](calc[i](a[1], calc[j](a[2], a[3])), a[4]) == 24)
				res[++tot] += string("((") + (char)(a[1] + '0') + sym[i] + string("(") + (char)(a[2] + '0') + sym[j] + (char)(a[3] + '0') + string("))") + sym[k] + (char)(a[4] + '0') + string(")");
			if (calc[i](a[1], calc[k](calc[j](a[2], a[3]), a[4])) == 24)
				res[++tot] += string("(")  + (char)(a[1] + '0') + sym[i] + string("((") + (char)(a[2] + '0') + sym[j] + (char)(a[3] + '0') + string(")") + sym[k] + (char)(a[4] + '0') + string("))");
			if (calc[i](a[1], calc[j](a[2], calc[k](a[3], a[4]))) == 24)
				res[++tot] += string("(")  + (char)(a[1] + '0') + sym[i] + string("(") + (char)(a[2] + '0') + sym[j] + string("(") + (char)(a[3] + '0') + sym[k] + (char)(a[4] + '0') + string(")))");

		}
	}
	while (next_permutation(a + 1, a + 5));
	sort(res + 1, res + tot + 1);
	cout << res[1] << endl;
	return 0;
}
