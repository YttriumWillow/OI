#include<bits/stdc++.h>
using namespace std;
map<int, int> pos;//pos[i] 记录 i 最后一次出现的位置 
const int max_n = 5e5 + 5;
int l[max_n], r[max_n];//线段的左右端点 
int Log[max_n], f[20][max_n];
inline void init(int n)//ST 表预处理 
{
    Log[0] = -1;
    for (int i = 1; i <= n; ++i) {
        Log[i] = Log[i >> 1] + 1;
        f[0][i] = r[i] - l[i];//值为线段长度 
    }
    for (int i = 1; i <= Log[n]; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
}
inline int query(int l, int r)//ST 表查询区间最小值 
{
    int k = Log[r - l + 1];
    return min(f[k][l], f[k][r - (1 << k) + 1]);
}
int main() {
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        int id = pos[x];
        if (id != 0) {
            if (id > l[cnt])//判断是否包含 
                l[++cnt] = id, r[cnt] = i;
        }
        pos[x] = i;
    }
    init(cnt);
    for (int i = 1; i <= m; ++i) {
        int L, R;
        scanf("%d%d", &L, &R);
        int x = lower_bound(l + 1, l + cnt + 1, L) - l;
        int y = upper_bound(r + 1, r + cnt + 1, R) - r - 1;
        if (x <= y)
            printf("%d\n", query(x, y));
        else//若 x>y 则无解 
            puts("-1");
    }
    return 0;
}
