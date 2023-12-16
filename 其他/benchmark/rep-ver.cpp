#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;

struct node
{
    int l, r;
} a[N << 1];

int ans = 1e9;
int st[30][N];

inline bool cmp(const node &p, const node &q)
{
    return p.l < q.l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++ i)
    {
        cin >> a[i].l >> a[i].r;
        if (a[i].l > a[i].r) a[i].r += n;
        a[m + i].l = a[i].l + n, a[m + i].r = a[i].r + n;
    }
    sort(a + 1, a + (m << 1) + 1, cmp);
    for (int i = 1; i <= m; ++ i)
    {
        int j = i + 1, l = a[i].l, r = a[i].r, cnt = 1;
        while (j < i + m && r < l + n - 1)
        {
            int res = 0;
            while (j < i + m && a[j].l <= r + 1)
                res = max(res, a[j].r), j ++ ;
            cnt ++ , r = res; if (a[j].l > r + 1) break;
        }
        if (r >= l + n - 1) ans = min(ans, cnt);
    }
    if (ans == 1e9) cout << "impossible";
    else cout << ans;
}