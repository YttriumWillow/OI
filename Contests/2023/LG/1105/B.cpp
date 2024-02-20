#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e3 + 10;

int n, m;
int cntA, cntR;
char A[N][N];
char B[N][N];
char R[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    rep (i, 1, n) cin >> A[i] + 1;
    rep (i, 1, n) cin >> B[i] + 1;

    rep (i, 1, n) rep (j, 1, m)
            R[i][j] = (A[i][j] == '.') ? 'X' : '.';

    rep (i, 1, n) rep (j, 1, m)
            cntA += (A[i][j] != B[i][j]);

    rep (i, 1, n) rep (j, 1, m)
            cntR += (R[i][j] != B[i][j]);

    if (cntA <= n * m / 2)
        rep (i, 1, n)
            cout << A[i] + 1 << endl;
    if (cntR <= n * m / 2)
        rep (i, 1, n)
            cout << R[i] + 1 << endl;
    
    return 0;
}