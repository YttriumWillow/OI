#include <bits/stdc++.h>
#define N 100005
#define mod 100000007
#define base 131
#define ll long long
using namespace std;
char a[N];
int n, l, r, res;
ll hash1[N], hash2[N], power[N], sum, ans, c1[N], c2[N], in[N][26], de[N];
ll get_h1(int x, int y) { return ((hash1[y] - hash1[x - 1] * power[y - x + 1]) % mod + mod) % mod; }
ll get_h2(int x, int y) { return ((hash2[x] - hash2[y + 1] * power[y - x + 1]) % mod + mod) % mod; }
void increase(int x, int y) {
    c1[x]++;
    c1[y + 1] -= (y - x + 2);
    c1[y + 2] += (y - x + 1);
}
void decrease(int x, int y) {
    c1[y + 2]++;
    c1[x] += (y - x + 1);
    c1[x + 1] -= (y - x + 2);
}
int main() {
    freopen("palinilap.in", "r", stdin);
    freopen("palinilap.out", "w", stdout);
    scanf("%s", a + 1);
    n = (int)strlen(a + 1);
    a[0] = '%';
    power[0] = 1ll;
    for (int i = 1; i <= n; i++) power[i] = power[i - 1] * base % mod;
    for (int i = 1; i <= n; i++) hash1[i] = (hash1[i - 1] * base + a[i]) % mod;
    for (int i = n; i >= 0; i--) hash2[i] = (hash2[i + 1] * base + a[i]) % mod;
    for (int i = 1; i < n; i++) {
        for (int j = i; j <= i + 1; j++) {
            l = 0;
            r = min(j, n - j + 1);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get_h1(i - mid + 1, i) == get_h2(j, j + mid - 1))
                    l = mid;
                else
                    r = mid - 1;
            }
            sum += (ll)l;
            if (l > 0) {
                if (i == j) {
                    increase(i - l + 1, i - 1);
                    decrease(j + 1, j + l - 1);
                } else {
                    increase(i - l + 1, i);
                    decrease(j, j + l - 1);
                }
            }
            if (i - l <= 0 || j + l > n)
                continue;
            int rl = l, pl = l;
#define temp1 in[i - pl][a[j + pl] - 'a']
#define temp2 in[j + pl][a[i - pl] - 'a']
            r = min(i - l - 1, n - j - l);
            l = 0;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get_h1(i - rl - mid, i - rl - 1) == get_h2(j + rl + 1, j + rl + mid))
                    l = mid;
                else
                    r = mid - 1;
            }
            temp1 += l + 1;
            temp2 += l + 1;
#undef temp1
#undef temp2
        }
    }
    for (int i = 1; i <= n; i++) {
        c2[i] = c2[i - 1] + c1[i];
        de[i] = de[i - 1] + c2[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == a[i] - 'a')
                continue;
            ans = max(ans, in[i][j] - de[i]);
        }
    }
    printf("%lld\n", ans + sum + 1);
    return 0;
}