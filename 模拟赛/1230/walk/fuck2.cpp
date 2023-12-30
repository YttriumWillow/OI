#include <cstdio>
#include <vector>
const int N = 4e5 + 10;
const int M = 1e6 + 10;
int head[N], to[N << 1], Next[N << 1], sta[N << 1], cnt;
void add(int u, int v)
{
    to[++cnt] = v, Next[cnt] = head[u], head[u] = cnt, sta[cnt] = u;
}
struct node {int u, v;} t;
int n, m, mxl, mx, used[N], ans[N];
std::vector <node> e[M];
int max(int x, int y) {return x > y ? x : y;}
int maxdis(int now, int fa)
{
    used[now] = 1;
    int mx0 = 0, mx1 = 0, d;
    for (int i = head[now]; i; i = Next[i])
    {
        int v = to[i];
        if (v != fa)
        {
            d = maxdis(v, now);
            if (d >= mx0) mx1 = mx0, mx0 = d;
            else if (d > mx1) mx1 = d;
        }
    }
    mxl = mxl > mx0 + mx1 ? mxl : mx0 + mx1;
    return mx0 + 1;
}
int main()
{
    scanf("%d", &n);
    for (int w, i = 1; i < n; i++)
    {
        scanf("%d%d%d", &t.u, &t.v, &w);
        e[w].push_back(t);
        mx = mx > w ? mx : w;
    }
    for (int i = 1; i <= mx; i++)
    {
        for (int j = i; j <= mx; j += i)
            for (int k = 0; k < e[j].size(); k++)
                add(e[j][k].u, e[j][k].v), add(e[j][k].v, e[j][k].u);
        mxl = 0;
        for (int j = cnt; j; j--)
            if (!used[sta[j]])
                maxdis(sta[j], 0);
        ans[mxl] = i;
        for (int j = 1; j <= cnt; j++) used[sta[j]] = 0, head[sta[j]] = 0;
        cnt = 0;
    }
    for (int i = n; i; i--) ans[i] = max(ans[i + 1], ans[i]);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}
