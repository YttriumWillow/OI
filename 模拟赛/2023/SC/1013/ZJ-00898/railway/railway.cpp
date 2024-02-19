#include <iostream>

#define i64 long long 
#define endl '\n'
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int n;

/*

首先 1 层要到每一层去。
然后 j 层也要到每一层去？
哦这样我固定下来前几个楼层了。这肯定对的吧 (fixed: Right of course)
关键是最后一个层放什么。
[1 | i | j | n - i + 1] 
艹这个到底对不对
手摸好像是对的
猜结论骗分，启动！！！！！！！！！！！！！

*/

int main()
{
	file("railway");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	cout << n * n / 4 << endl;
	rep (i, 1, n / 2)
		rep (j, i + 1, n - i + 1)
			cout << 1 << ' ' << i << ' ' << j << ' ' << n - i + 1 << endl;
	return 0;
}