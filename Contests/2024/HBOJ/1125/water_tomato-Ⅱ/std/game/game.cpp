#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N = 4005;
int ans[N][N], n;
int r[N], c[N];
char s[N][N];
priority_queue<pi, vector<pi>, less<pi> > q;
bool solve() {
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) continue;
        q.push({ c[i],i });
    }
    for (int i = 1; i <= n; i++) {
        if (r[i] < 0) return 0;
        vector<pi> tmp; tmp.clear();
        for (int j = 1; j <= r[i]; j++) {
            if (q.empty()) return 0;
            pi u = q.top(); q.pop();
            // printf("!%d %d %d\n",i,j,u.second);
            if (u.first != 1) {
                tmp.push_back({ u.first - 1,u.second });
            }
            ans[i][u.second] = 1;
        }
        for (auto x : tmp) {
            q.push(x);
        }
    }
    if (!q.empty()) return 0;
    return 1;
}
void True_solve() {
    scanf("%d", &n);
    // cout<<n<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '-') {
                r[i]++;
                c[j]++;
            }
        }
    }
    // printf("A");
    if (solve()) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) True_solve();
    return 0;
}