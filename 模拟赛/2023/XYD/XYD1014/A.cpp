#include <iostream>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define qwq puts("fzy qwq ~");
#define inrange(x, l, r) (l <= (x) && (x) <= r)

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

const int N = 510;

int n, m, res; char ch;
int g[N][N], o;

struct Node
{
    int x, y;
    friend bool operator < (const Node& A, const Node& B)
    { return (A.x ^ B.x) ? (A.x < B.x) : (A.y < B.y); }
} P[N * N]; int cnt;

int main()
{
    file("firstsnow");

    cin >> n >> o;

    rep (i, 1, n) rep (j, 1, n)
    {
        cin >> ch; g[i][j] = ch - '0';
        if (ch == '1') P[++cnt] = { i, j };
    }

    sort(P + 1, P + cnt + 1);

    rep (i, 1, cnt)
        rep (j, i + 1, cnt)
        {
            int x1 = P[i].x + P[i].y - P[j].y;
            int y1 = P[i].y + P[j].x - P[i].x;
            int x2 = P[j].x + P[i].y - P[j].y;
            int y2 = P[j].y + P[j].x - P[i].x;
            if (inrange(x1, 1, n) && inrange(y1, 1, n) && inrange(x2, 1, n) && inrange(y2, 1, n) && g[x1][y1] && g[x2][y2])
                ++res;
        }
    cout << res / 2 << endl;

    return 0;
}
