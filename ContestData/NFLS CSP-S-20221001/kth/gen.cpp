#include "testlib.h"
#include <iostream>
#include <vector>
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

    int Ln = opt<int>("n");
    int Q = opt<int>("Q");
    int V = opt<int>("V");

	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n = rnd.wnext(1, Ln, 10);
    int m = rnd.wnext(1, Ln, 10);
    V = min(V, max(n, m));

    cout << n << ' ' << m << ' ' << Q << endl;

    vector<int> Qrys;

    const int part1 = Q / 10;
    // cerr << sqrt(V) << endl;

    rep (T, 1, part1)
    {
        Qrys.push_back(rnd.wnext(1, (int)sqrt(V), 2));
    }
    // cerr << "Gs" << endl;

    rep (T, 1, Q - part1)
    {
        Qrys.push_back(rnd.wnext((int)sqrt(V), V, 2));
    }
    // cerr << "impact" << endl;

    shuffle(Qrys.begin(), Qrys.end());

    rep (i, 0, (int)Qrys.size() - 1)
        cout << Qrys[i] << " \n"[i == (int)Qrys.size() - 1];

    return 0;
}