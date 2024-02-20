#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 3e3 + 10;

int n, a[N], b[N];
int k;
vector<int> L, R;

inline void resort(int l, int r)
{
    // int len = r - l + 1;
    static int t[2][N];
    int cnt[2] = { 0, 0 }, p = 1;
    rep (i, l, r)
        t[p][++cnt[p]] = a[i], p ^= 1;
    rep (i, 1, cnt[0])
        a[l + i - 1] = t[0][i];
    rep (i, 1, cnt[1])
        a[l + cnt[0] + i - 1] = t[1][i];
}

inline bool increasing(int l, int r)
{
    rep (i, l + 1, r)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();

    rep (i, 1, n)
    {
        a[i] = inf.readInt();
        b[i] = a[i];
    }

    int k = ouf.readInt();

    rep (i, 1, k)
    {
        L[i] = ouf.readInt();
        R[i] = ouf.readInt();
    }

    if (k > 30000) quitf(_wa, "[ERROR] Your total operation number is TOO BIG! k=%d", k);

    rep (i, 1, k)
    {
        int &l = L[i], &r = R[i];
        if (l <= 0 or l > n) quitf(_wa, "[ERROR] Your operation is out of range: L[%d]=%d n=%d", i, l, n);
        if (r <= 0 or r > n) quitf(_wa, "[ERROR] Your operation is out of range: R[%d]=%d n=%d", i, r, n);
        if (l > r) quitf(_wa, "[ERROR] Your operation is invalid: L,R[%d]=%d,%d", i, l, r);
        resort(l, r);
    }

    bool validity = increasing(1, n);

    if (!validity) quitf(_wa, "[ERROR] Your operation is invalid. The senquece is unincreasing");

    quitf(_ok, "[SUCCESS] A wonderful answer!");

    return 0;
}
