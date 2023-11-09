#include <iostream>
#include <cstdlib>
#include <set>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int s1, s3, tot;

int main()
{
	file("ensata");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s1 >> s3;

	if(!s1 && !s3) return cout << 1, 0;
	else if(s1 < s3 + 2 || s1 == s3 + 3)
		return cout << 0, 0;
	else
	{
		if(s1 == s3 + 2) cout << s1 + s3 << '\n';
		else cout << s1 + s3 + 1 << '\n';
		int cnt = 1;
		for(int i = 1; i <= s3; ++ i)
			cout << ++ cnt << ' ' <<  i << '\n';
		cout << "1 " << ++ cnt << '\n';
		for(int i = 1; i <= s3; ++ i)
			cout << i << ' ' <<  ++ cnt << '\n';
		if(cnt < s1 + s3)
			for(int i = cnt + 1; i <= s1 + s3 + 1; ++ i)
				cout << s3 + 1 << ' ' << i << '\n';
	}

	return 0;
}