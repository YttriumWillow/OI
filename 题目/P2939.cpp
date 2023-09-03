// Problem:       P2939 [USACO09FEB]Revamping Trails G
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P2939
// Memory Limit:  125 MB
// Time Limit:    2000 ms
// Created Time:  2023-06-22 14:38:03 

// Problem:       P4568 [JLOI2011] 飞行路线
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P4568
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-05-28 12:40:17

#include <iostream>

#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define Pii pair<i64, i64>
#define pb push_back
#define qwq puts("fzy qwq ~");
	
using namespace std;

const i64 N = 5e5 + 10;
const i64 M = 4e7 + 10;
const i64 inf = 0xfffffffffffff;

i64 n, m, s, t, k;
i64 u, v, w;
i64 dis[N]; bool vis[N];
i64 ans = inf;

vector<Pii> g[N];

priority_queue<Pii, vector<Pii>, greater<Pii>> q;

inline void Dijkstra()
{
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0; q.push({ 0, s });
    
    while (!q.empty())
    {
        Pii faq = q.top(); q.pop();
        i64 u = faq.second; 
        
        if (vis[u]) continue;
        vis[u] = 1;
        
        for (auto now : g[u])
        {
            i64 v = now.first;
            i64 w = now.second;
            if (dis[v] > dis[u] + w && !vis[v])
            {
                dis[v] = dis[u] + w;
                q.push({ dis[v], v });
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    // cin >> s >> t;
    
	// 
    s = 1; t = n;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        g[u].pb({ v, w });
        g[v].pb({ u, w });
        for (int j = 1; j <= k; ++j)
        {
            g[u + j * n].pb({ v + j * n, w });
            g[v + j * n].pb({ u + j * n, w });
            g[u + (j - 1) * n].pb({ v + j * n, 0 });
            g[v + (j - 1) * n].pb({ u + j * n, 0 });
            
        }
    }
    Dijkstra();
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dis[t + n * i]);
    cout << ans << endl;
    return 0;
}