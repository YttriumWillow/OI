#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1002;
int n, q, a[N][N], f[N][N], g[N][N];
struct node {
    int x, id;
} b[N][2];
int main() {
    freopen("num.in", "r", stdin);
    freopen("num.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) b[i][0].x = b[i][1].x = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) {
            scanf("%d", a[i] + j);
            f[i][j] = a[i][j] + max(f[i - 1][j - 1], f[i - 1][j]);
        }
    for (int i = n; i; --i)
        for (int j = 1; j <= i; ++j) {
            g[i][j] = a[i][j] + max(g[i + 1][j], g[i + 1][j + 1]);
            node tmp = { f[i][j] + g[i][j] - a[i][j], j };
            if (tmp.x > b[i][0].x)
                b[i][1] = b[i][0], b[i][0] = tmp;
            else if (tmp.x > b[i][1].x)
                b[i][1] = tmp;
        }
    for (int x, y; q--;) {
        scanf("%d%d", &x, &y);
        printf("%d\n", b[x][b[x][0].id == y].x);
    }
    return 0;
}