1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
#include <bits/stdc++.h>
using namespace std;
const int maxn = 330, mod = 998244353;
int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };
int n, m, k, r, xx, yy, cnt, dir, stp, mx, f[666], cntf[222222], re[222222], cntg, ans, cnr;
int x[333], y[333], id[666][666], cur[222222], to[222222];
vector<int> v[555555], buc;
int binpow(int a, int t) {
    int res = 1, p = a;
    for (int i = t; i; i >>= 1) {
        if (i & 1) res = 1ll * res * p % mod;
        p = 1ll * p * p % mod;
    }
    return res;
}
int Get(int x, int y) {
    return (x - 1) * m + y;
}
void split(int a, int b, int c) // /(1 + ax) * (1 + bx) * (1 + cx)
{
    assert(b + c == a);
    for (int i = 1; i <= r; i++) {
        f[i] = (-1ll * f[i - 1] * a + f[i]) % mod;
    }
    for (int i = r; i >= 1; i--) {
        f[i] = (1ll * f[i - 1] * b + f[i]) % mod;
    }
    for (int i = r; i >= 1; i--) {
        f[i] = (1ll * f[i - 1] * c + f[i]) % mod;
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 1; i <= k; i++) scanf("%d%d", &x[i], &y[i]);
    id[maxn][maxn] = 1; id[maxn + 1][maxn] = 2;
    cnt = 2; xx = 1; yy = 0; dir = 0;
    while (1) {
        xx += dx[dir]; yy += dy[dir];
        if (xx > maxn || xx < -maxn || yy > maxn || yy < -maxn) break;
        cnt++;
        id[xx + maxn][yy + maxn] = cnt;
        if (!id[xx + dx[(dir + 1) % 4] + maxn][yy + dy[(dir + 1) % 4] + maxn]) dir = (dir + 1) % 4;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int h = 1; h <= k; h++) {
                mx = max(mx, id[x[h] - i + maxn][y[h] - j + maxn]);
                v[id[x[h] - i + maxn][y[h] - j + maxn]].push_back(Get(i, j));
            }
        }
    }
    cnr = 1;
    for (int i = 1; i <= r; i++) {
        cnr = 1ll * cnr * (n * m - i + 1) % mod;
        cnr = 1ll * cnr * binpow(i, mod - 2) % mod;
    }
    f[0] = 1; f[1] = n * m; ans = (cnr - f[r]) % mod;
    for (int i = 1; i <= n * m; i++) {
        re[i] = 1;
    }
    cntf[1] = n * m; cntg = 1;
    for (int i = 1; i <= mx; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int idx = v[i][j];
            if (!cur[re[idx]]) buc.push_back(re[idx]);
            cur[re[idx]]++;
        }
        for (int j = 0; j < buc.size(); j++) {
            if (cur[buc[j]] == cntf[buc[j]]) continue;
            ++cntg;
            to[buc[j]] = cntg;
            split(cntf[buc[j]], cur[buc[j]], cntf[buc[j]] - cur[buc[j]]);
            cntf[buc[j]] -= cur[buc[j]];
            cntf[cntg] = cur[buc[j]];
        }
        for (int j = 0; j < v[i].size(); j++) {
            int idx = v[i][j];
            if (to[re[idx]]) re[idx] = to[re[idx]];
        }
        for (int j = 0; j < buc.size(); j++) {
            cur[buc[j]] = to[buc[j]] = 0;
        }
        buc.clear();
        ans = (1ll * ans + cnr - f[r]) % mod;
        if (cntg == n * m) break;
    }
    for (int i = 1; i <= n * m; i++) assert(cntf[re[i]] == 1);
    ans = 1ll * ans * binpow(cnr, mod - 2) % mod;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}