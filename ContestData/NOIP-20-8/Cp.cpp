#include <bits/stdc++.h>
typedef long long ll;

int a[3001], b[3001], a_[3001], bit[(1 << 12) + 1], ope[30001][2], tot;

ll read() {
    ll ans_ = 0, f = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-')f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { ans_ = ans_ * 10 + c - '0'; c = getchar(); }
    return f * ans_;
}

inline void add(int x) {
    for (int i = x; i <= (1 << 12); i += (i & (-i)))bit[i]++;
}

inline int pre(int x) {
    int ans = 0;
    for (int i = x; i; i ^= (i & (-i)))ans += bit[i];
    return ans;
}

int main() {

    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n = read(), minrop, rop;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        while (a[i] != i) {
            ope[++tot][0] = i + 1 - ((b[i] - i) & 1);
            memset(bit, 0, sizeof(bit)); minrop = 0; rop = 0;
            for (int j = ope[tot][0]; j <= n; j++) {
                if ((j - ope[tot][0]) & 1)rop += 2 * pre(a[j]) - ((j - ope[tot][0] + 1) >> 1);
                else add(a[j]);
                if (rop < minrop || j == b[i]) {
                    ope[tot][1] = j;
                    minrop = rop;
                }
            }
            for (int j = ope[tot][0], k = ope[tot][0] + 1; j <= ope[tot][1]; j++) {
                if (k > ope[tot][1])k = ope[tot][0];
                a_[j] = a[k]; k += 2;
            }
            for (int j = ope[tot][0]; j <= ope[tot][1]; j++) {
                a[j] = a_[j];
                b[a[j]] = j;
            }
        }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++)printf("%d %d\n", ope[i][0], ope[i][1]);
    return 0;
    return 0;
}