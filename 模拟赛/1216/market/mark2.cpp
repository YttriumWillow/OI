#include <cstdio>
#include <algorithm>
#define file(prob) freopen(prob".in", "r", stdin);freopen(prob".out", "w", stdout);

using namespace std;

struct Mark{
    int c, v, t;
    bool operator < (const Mark &rhs) const {
        return t < rhs.t;
    }
} market[305];

struct Qry{
    int t, m, id;
    bool operator < (const Qry &rhs) const {
        return t < rhs.t;
    }
} qry[100005];

int g[90005];
int qans[100005];

inline void flush(int u){
    for (int i = 90000; i >= market[u].c; --i){
        if (g[i] > g[i - market[u].c] + market[u].v)
            g[i] = g[i - market[u].c] + market[u].v;
    }
    for (int i = 90000; i >= 1; --i)
        if (g[i] > g[i + 1]) g[i] = g[i + 1];
}

int main(){
    file("mark2");
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d %d", &market[i].v, &market[i].c, &market[i].t);
    sort(market + 1, market + n + 1);
    for (int i = 1; i <= m; ++i){
        int t, m; scanf("%d %d", &t, &m);
        qry[i] = {t, m, i};
    }
    sort(qry + 1, qry + m + 1);
    for (int i = 1; i <= 90004; ++i) g[i] = 1000000007;
    for (int i = 1, pos = 1; i <= m; ++i){
        for ( ; market[pos].t <= qry[i].t && pos <= n; ++pos)
            flush(pos);
        qans[qry[i].id] = upper_bound(g, g + 90001, qry[i].m) - g - 1;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", qans[i]);
    return 0;
}