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

int n, Q, X, spc;
int G[1010][1010];
int f[1010][1010];
pair<int, int> nxt[1010][1010];

inline void general()
{
    rep (i, 1, n)
    {
        rep (j, 1, i)
        {
            int p = rnd.next(1, X);
            // Val.push_back(p);
            G[i][j] = p;
            cout << p << " \n"[j == i];
        }
    }
}

inline void spc1() // (i * j)
{
    rep (i, 1, n)
    {
        rep (j, 1, i)
        {
            int p = i * j;
            G[i][j] = p;
            cout << p << " \n"[j == i];
        }
    }
}

inline void spc2() // (i - j)
{
    rep (i, 1, n)
    {
        rep (j, 1, i)
        {
            int p = i - j;
            G[i][j] = p;
            cout << p << " \n"[j == i];
        }
    }
}

inline void spc3(int bsc) // (i * j)
{
    rep (i, 1, n)
    {
        rep (j, 1, i)
        {
            int p = bsc;
            G[i][j] = p;
            cout << p << " \n"[j == i];
        }
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    n = opt<int>("n");
    Q = opt<int>("Q");
    X = opt<int>("X");
    spc = opt<int>("spc");

	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    n = rnd.wnext((int)sqrt(n), n, 5);
    Q = rnd.wnext((int)sqrt(Q), Q, 5);

    cout << n << ' ' << Q << endl;

    if (spc == 0)
        general();
    else if (spc == 1) // (i * j)
        spc1();
    else if (spc == 2) // (i - j)
        spc2();
    else // (=)
        spc3(spc);

    

    // sort(Val.begin(), Val.end());
    // auto pos = unique(Val.begin(), Val.end());
    // Val.erase(pos, Val.end());

    // for (int i = n; i >= 1; --i)
    // {
    //     rep (j, 1, i)
    //     {
    //         f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + G[i][j];
    //         prv[]
    //     }
    // }

    hack1();

    rep (T, 1, Q)
    {
        int i = rnd.next(1, n);
        int j = rnd.next(1, i);
        cout << i << ' ' << j << "\n";
    }
    


    return 0;
}