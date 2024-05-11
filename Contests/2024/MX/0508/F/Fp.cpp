#include<bits/stdc++.h>
using namespace std;
#define Mul(a) ((long long)(a) * (a))
const int N = 1e5 + 10;
typedef pair<int, int> Node;
int n, m;         //点、边
Node a[N];        //n个点的坐标
struct edge {
    int u, v;
    long long w;
}e[N * 22];           //边的数量。如果只连左边的11条边，这里改为N*11
bool cmp(edge a, edge b) { return a.w < b.w; }    //从小到大排序
void add_edge(int u, int v) {  //点u和点v连边
    m++;
    e[m].u = u;
    e[m].v = v;
    e[m].w = Mul(a[u].first - a[v].first) + Mul(a[u].second - a[v].second);
}
int s[N];//并查集
int find_set(int x) {      //查询并查集，返回x的根
    if (x != s[x])
        s[x] = find_set(s[x]);     //路径压缩
    return s[x];
}
void kruskal() {
    for (int i = 1; i <= n; i++)  s[i] = i;    //并查集初始化
    sort(e + 1, e + 1 + m, cmp);               //边排序
    long long ans = 0;
    for (int i = 1; i <= m; i++) {              //从小到大遍历边，加入到最小生成树
        int u = find_set(e[i].u), v = find_set(e[i].v);
        if (u == v) continue;                    //产生了圈，丢弃
        else  s[u] = v, ans += e[i].w;
    }
    cout << ans << endl;
}
int Last[15];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);                    //对点排序。实际是对x从小到大排序
    //每个点往每行的左边最近点连边
    for (int i = 0; i <= 10; i++)   Last[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int y = 0; y <= 10; y++)
            if (Last[y])   add_edge(i, Last[y]);
        Last[a[i].second] = i;
    }
    //每个点往每行的右边最近点连边。可以省略
 /* for(int i = 0; i <= 10; i++)Last[i] = 0;
    for(int i = n; i >= 1; i--) {
        for(int y = 0; y <= 10; y++)
            if(Last[y])   add_edge(i, Last[y]);
        Last[a[i].second] = i;
    }*/
    kruskal();
    return 0;
}

