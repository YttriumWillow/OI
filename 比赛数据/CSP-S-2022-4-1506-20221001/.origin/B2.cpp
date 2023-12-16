#pragma GCC optimize(2)
#include <cstdio>
#include <algorithm>
#include <cstring>
#define db double
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
#define M 1005
int n, m, a[M][M], up[M][M], down[M][M];
int m1[M], m2[M], pos[M];
int main() {
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) a[i][j] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) up[i][j] = max(up[i - 1][j - 1], up[i - 1][j]) + a[i][j];
    for (int i = n; i; i--)
        for (int j = 1; j <= i; j++) down[i][j] = max(down[i + 1][j], down[i + 1][j + 1]) + a[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int t = up[i][j] + down[i][j] - a[i][j];
            if (t > m1[i])
                m2[i] = m1[i], m1[i] = t, pos[i] = j;
            else if (t > m2[i])
                m2[i] = t;
        }
    }
    while (m--) {
        int x = read(), y = read();
        if (x == 1 && y == 1)
            puts("-1");
        else if (pos[x] == y)
            printf("%d\n", m2[x]);
        else
            printf("%d\n", m1[x]);
    }
    return 0;
}