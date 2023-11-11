#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

i64 s[10];
i64 _3, _8, _10;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7] >> s[8]; 

	rep (i, 1, 8)
	{
		_3 += (s[i] >= 41);
		_8 += (s[i] >= 63);
		_10 += (s[i] >= 118);
	}

	if (_10 >= 1)
		cout << 10 << endl;
	else if (_8 >= 4)
		cout << 8 << endl;
	else if (_3 >= 4)
		cout << 3 << endl;
	else cout << 1 << endl;
	return 0;
}