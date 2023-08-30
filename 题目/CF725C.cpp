#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

string s;
int vis[260];
int n, posl, posr;
char res[3][30];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; n = 27;
	s = '#' + s;

	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 13; ++j)
			res[i][j] = '?';

	for (int i = 1; i <= n; ++i)
		vis[(int)s[i]] ? posr = i : vis[(int)s[i]] = i; 
	posl = vis[(int)s[posr]];

	int ed1 = ((posl + posr) >> 1); if ((posr - posl + 1) & 1) --ed1;

	if (posr - posl == 1) { cout << "Impossible" << endl, exit(0); }
	// 1, 13 -> ed1
	for (int i = ed1; i >= posl; --i)
		res[1][13 - (ed1 - i)] = s[i];

	for (int i = ed1 + 1; i < posr; ++i)
		res[2][13 - (i - ed1 - 1)] = s[i];

	// for (int i = 1; i <= 2; ++i)
	// 	for (int j = 1; j <= 13; ++j)
	// 		cerr << res[i][j] << " \n"[j == 13];

	int fwd = -1, xx = 1, yy = 13 - (ed1 - posl) - 1;


		// if (yy == 1 && xx == 1) xx = 2, fwd = 1;
		// else yy += fwd;
	
	if (yy == 0) yy = 1, xx = 2;

	for (int i = posl - 1; i >= 1; --i)
	{
		res[xx][yy] = s[i];
		// cerr << "p(" << xx << ',' << yy << ") is " << s[i] << endl;
		if (yy == 1 && xx == 1) xx = 2, fwd = 1;
		else yy += fwd;
	}

	if (yy == 0) yy = 1, xx = 2;

	for (int i = n; i > posr; --i)
	{
		res[xx][yy] = s[i];
		// if (s[i] == 'Q') cerr << "? " << xx << ' ' << yy << endl;
		// cerr << "p(" << xx << ',' << yy << ") is " << s[i] << endl;
		if (yy == 1 && xx == 1) xx = 3 - xx, fwd = 0 - fwd;
		else yy += fwd;
	}

	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= 13; ++j)
			cout << res[i][j];
		cout << endl;
	}

	return 0;
}
