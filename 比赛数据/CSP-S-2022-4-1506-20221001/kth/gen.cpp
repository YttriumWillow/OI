#include "testlib.h"
#include <iostream>
#include <regex>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int m = opt<int>("m");

	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << n << ' ' << m << endl;

    rep (T, 1, m)
    {
        int k = rnd.next(1, n);

        vector<int> vec;
        rep (i, 1, k)
            vec.push_back(rnd.next(1, n));

        sort(vec.begin(), vec.end());
        auto pos = unique(vec.begin(), vec.end());
	    vec.erase(pos, vec.end());

        shuffle(vec.begin(), vec.end());

		k = vec.size();
		cout << k << ' ';

        rep (i, 0, (int)vec.size() - 1)
            cout << vec[i] << " \n"[i == (int)vec.size() - 1];
    }

    return 0;
}