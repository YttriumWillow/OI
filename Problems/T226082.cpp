#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m, maxh, tl, tr, th, piece;
char ch;
struct Seg
{
    longint l, r;
    Seg (longint a, longint b) :l(a), r(b) {}
};
struct Floor
{
    list<Seg> seg;
} floors[500010];
longint ans;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
void work(longint now, longint h)
{
    for (int i = h; i >= 0; i--)
    {
        list<Seg>::iterator j;
        for (j = floors[i].seg.begin(); j != floors[i].seg.end(); j++)
            if (now >= (*j).l && now <= (*j).r)
            {
                // floors[i].seg[j].get = true;
                work((*j).l, i - 1);
                work((*j).r, i - 1);
                return;
            }
    }
    // printf("%d add one!\n", now);
    ans++;
}
int main()
{
    n _read; m _read;
    for (int i = 1; i <= n; i++)
    {
        tl _read; tr _read; th _read;
        floors[th].seg.push_back(Seg(tl, tr));
        maxh = max(maxh, th);
    }
    for (int i = 1; i <= m; i++)
    {
        piece _read;
        work(piece, maxh);
    }
    cout << ans << endl;
    return 0;
}