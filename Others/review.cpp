#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq !");
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)

using namespace std;


// 1
class SGT
{
private:
	int query(int p, int l, int r)
	{
		cerr << l << ' ' << r << ' ' << p << endl;
		return 0;
	}
public:
	int query(int l, int r) { return query(1, l, r); }
};

// 2
inline int query(int l, int r, int p = 1)
{
	cerr << l << ' ' << r << ' ' << p << endl;
	return 0;
}

int main()
{
	// 1
	SGT t;
	cout << t.query(1, 10) << endl;
	// 2
	cout << query(1, 10) << endl;

	return 0;
}