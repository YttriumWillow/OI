#include <bits/stdc++.h>
using namespace std;
const int base[] = { 131, 13331 }, mod[] = { 1000000007, 998244353 };
char a[100005];
long long h0[2][100005], h1[2][100005], pw[2][100005], res[27][100005], cf[100005];
inline long long ha0(int k, int l, int r) {
    return ((h0[k][r] - h0[k][l - 1] * pw[k][r - l + 1]) % mod[k] + mod[k]) % mod[k];
}
inline long long ha1(int k, int l, int r) {
    return ((h1[k][l] - h1[k][r + 1] * pw[k][r - l + 1]) % mod[k] + mod[k]) % mod[k];
}
int main() {
    freopen("palinilap.in", "r", stdin);
    freopen("palinilap.out", "w", stdout);
    scanf("%s", a + 1);
    int n = strlen(a + 1), i, j, L, R, M;
    long long ans = 0, mx = 0;
    pw[0][0] = pw[1][0] = 1;
    for (i = 1; i <= n; i++) {
        h0[0][i] = (h0[0][i - 1] * base[0] + a[i] - 'a' + 1) % mod[0];
        h0[1][i] = (h0[1][i - 1] * base[1] + a[i] - 'a' + 1) % mod[1];
        pw[0][i] = pw[0][i - 1] * base[0] % mod[0];
        pw[1][i] = pw[1][i - 1] * base[1] % mod[1];
    }
    for (i = n; i; i--) {
        h1[0][i] = (h1[0][i + 1] * base[0] + a[i] - 'a' + 1) % mod[0];
        h1[1][i] = (h1[1][i + 1] * base[1] + a[i] - 'a' + 1) % mod[1];
    }
    for (i = 1; i <= n; i++) {
        L = 0, R = min(i, n - i + 1);
        while (L + 1 < R) {
            M = (L + R) >> 1;
            if (ha0(0, i - M, i) == ha1(0, i, i + M) && ha0(1, i - M, i) == ha1(1, i, i + M))
                L = M;
            else
                R = M;
        }
        ans += L + 1;
        cf[i - L]++, cf[i]--;
        cf[i] -= L, cf[i + 1] += L;
        cf[i + 1] += L, cf[i + 2] -= L;
        cf[i + 2]--, cf[i + L + 2]++;
        if (i - L == 1 || i + L == n)
            continue;
        int rg = L;
        L++, R = min(i, n - i + 1);
        while (L + 1 < R) {
            M = (L + R) >> 1;
            if (ha0(0, i - M, i - rg - 2) == ha1(0, i + rg + 2, i + M) &&
                ha0(1, i - M, i - rg - 2) == ha1(1, i + rg + 2, i + M))
                L = M;
            else
                R = M;
        }
        res[a[i + rg + 1] - 'a'][i - rg - 1] += L - rg;
        res[a[i - rg - 1] - 'a'][i + rg + 1] += L - rg;
    }
    for (i = 1; i < n; i++) {
        L = 0, R = min(i, n - i) + 1;
        while (L + 1 < R) {
            M = (L + R) >> 1;
            if (ha0(0, i - M + 1, i) == ha1(0, i + 1, i + M) && ha0(1, i - M + 1, i) == ha1(1, i + 1, i + M))
                L = M;
            else
                R = M;
        }
        ans += L;
        cf[i - L + 1]++, cf[i + 1]--;
        cf[i + 2]--, cf[i + L + 2]++;
        if (!(i - L) || i + L == n)
            continue;
        int rg = L;
        L++, R = min(i, n - i) + 1;
        while (L + 1 < R) {
            M = (L + R) >> 1;
            if (ha0(0, i - M + 1, i - rg - 1) == ha1(0, i + rg + 2, i + M) &&
                ha0(1, i - M + 1, i - rg - 1) == ha1(1, i + rg + 2, i + M))
                L = M;
            else
                R = M;
        }
        res[a[i + rg + 1] - 'a'][i - rg] += L - rg;
        res[a[i - rg] - 'a'][i + rg + 1] += L - rg;
    }
    for (i = 1; i <= n; i++) cf[i] += cf[i - 1];
    for (i = 1; i <= n; i++) cf[i] += cf[i - 1];
    for (i = 1; i <= n; i++)
        for (j = 0; j < 26; j++) mx = max(mx, res[j][i] - cf[i]);
    printf("%lld", ans + mx);
    return 0;
}