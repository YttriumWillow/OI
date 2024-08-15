#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
    return x * f;
}
namespace BT {
    LL c[N];
    int lowbit(int x) { return x & -x; }
    void add(int x, LL y) { for (; x < N; x += lowbit(x)) c[x] += y; }
    LL ask(int x) {
        LL res = 0;
        for (; x; x -= lowbit(x)) res += c[x];
        return res;
    }
}
int n, l[N], r[N], id[N], k;//指针 
LL a[N], pre[N], suf[N], Maxn[2][25][N], res = -1e18, sum[N];// 0 -> pre  1 -> suf 
LL query(int t, int l, int r) {
    int k = log2(r - l + 1);
    return max(Maxn[t][k][l], Maxn[t][k][r - (1 << k) + 1]);
}
void build_ST() {
    for (int i = 1; i <= n; i++) {
        Maxn[0][0][i] = pre[i];
        Maxn[1][0][i] = suf[i];
    }
    for (int i = 1; i <= 24; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            Maxn[0][i][j] = max(Maxn[0][i - 1][j], Maxn[0][i - 1][j + (1 << (i - 1))]);
            Maxn[1][i][j] = max(Maxn[1][i - 1][j], Maxn[1][i - 1][j + (1 << (i - 1))]);
        }
    }
}
bool cmp(int x, int y) { return ((a[x] < a[y]) || (a[x] == a[y] && x < y)); }
void solve() {
    LL ans = -1e18, del = 1e18;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        del = min(del, sum[i - 1]);
        ans = max(ans, sum[i] - del);
    }
    printf("%lld\n", ans);
}
int main() {
    n = read(); k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = 1LL * read();
    }
    if (k == 0) solve();
    else {
        for (int i = 1; i <= n; i++) {
            l[i] = i - 1; r[i] = i + 1;
            id[i] = i; pre[i] = pre[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i--)
            suf[i] = suf[i + 1] + a[i];
        build_ST();
        sort(id + 1, id + n + 1, cmp);//从小到大依次枚举第 k 大的数字, 枚举第 k + 1 大可能会有点难写 
        for (int i = 1; i <= n; i++) {
            int p = id[i];// p是第k大， 我们钦定大小大小相同的数也有一个相对大小 
            int cnt = 1, rt = p;
            LL sum = 0;
            while (cnt < k && r[rt] != n + 1) {
                cnt++; rt = r[rt];
                sum += a[rt];
            }
            int lt = p;
            while (cnt < k) {
                if (l[p] == 0) break;
                lt = l[lt], cnt++;
                sum += a[lt];
            }
            if (cnt == k) {//够 
                while (lt != 0 && rt >= p) {
                    res = max(res, query(0, rt, r[rt] - 1) + query(1, l[lt] + 1, lt) - pre[p] - suf[p] - sum);
                    sum -= a[rt];
                    rt = l[rt];
                    lt = l[lt];
                    sum += a[lt];
                }
            }
            r[l[p]] = r[p];
            l[r[p]] = l[p];
        }
        printf("%lld\n", res);
    }
    return 0;
}
/*
10 1
2 5 2 3 -1 0 12 6 2 -4
*/
