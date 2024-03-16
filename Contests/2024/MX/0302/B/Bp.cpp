#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5, M = 3005;
int n, m;
char a[N], b[M];
int nxt[N][26];
int f[M][M];
void solve() {
    cin >> n >> a + 1 >> m >> b + 1;
    for (int i = 0 ; i < 26 ; ++i) {
        int cur = INF;
        for (int j = n ; j >= 0 ; --j) {
            int t = a[j] - 'a';
            nxt[j][i] = cur;
            if (t == i) cur = j;
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0 ; i <= m ; ++i) f[i][0] = 0;
    for (int i = 1 ; i <= m ; ++i) {
        int t = b[i] - 'a';
        for (int j = 1 ; j <= i ; ++j) {
            f[i][j] = f[i - 1][j];
            if (f[i - 1][j - 1] <= n) f[i][j] = min(f[i][j], nxt[f[i - 1][j - 1]][t]);
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= m ; ++i) {
        if (f[m][i] >= INF) break;
        ans = i;
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    solve();
    return 0;
}