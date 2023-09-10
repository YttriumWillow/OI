#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long 
#define ld long double
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const ld eps = 1e-19;

#define lfabs(p) ((p) > 0 ? (p) : -(p))
// inline ld lfabs(ld p) { return p > 0 ? p : -p; }
#define equal(p, q) (fabs(p - q) <= eps)

ld x;

int main()
{
	// freopen("divide.in", "r", stdin);
	// freopen("divide.out", "w", stdout);

	cin >> x;
	i64 ul = 0, ur = 1;
	i64 dl = 1, dr = 0;
	while (1)
	{
		i64 um = ul + ur;
		i64 dm = dl + dr;
		ld v = (ld)um / dm;
		if ( equal(v, x) )
		{
			cout << um << ' ' << dm << endl;
			return 0;
		}

		else if (v > x) ur = um, dr = dm;
		else 	   ul = um, dl = dm;
	}
}