#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int binpow(int a, int t) {
    int res = 1, p = a;
    for (int i = t; i; i >>= 1) {
        if (i & 1) res = 1ll * res * p % mod;
        p = 1ll * p * p % mod;
    }
    return res;
}
int n, m, cnt;
char s[555];
int a[55][55], b[55][55], arr[55], cur, mat[555][555], iv, c[55][55], res[555];
int p[55], ap[555][55];
map<int, int> mp;
void dfs(int i, int j, int msk) {
    if (i == n + 1) {
        mp[msk] = ++cnt;
        for (int k = 1; k <= n; k++) ap[cnt][k] = p[k];
        return;
    }
    for (int k = 0; k <= j; k++) {
        p[i] = k;
        dfs(i + 1, k, msk * (m + 1) + k);
    }
}
int get(int a[55][55]) {
    for (int i = n; i >= 1; i--) {
        arr[i] = 0;
        for (int j = m; j >= 1; j--) {
            if (a[i][j] != b[i][j]) {
                arr[i] = j;
                break;
            }
        }
        if (i != n) arr[i] = max(arr[i], arr[i + 1]);
    }
    int msk = 0;
    for (int i = 1; i <= n; i++) {
        msk = msk * (m + 1) + arr[i];
    }
    return mp[msk];
}
void gauss() {
    for (int i = 1; i <= cnt; i++) {
        int pos = -1;
        for (int j = i; j <= cnt; j++) {
            if (mat[j][i]) {
                pos = j;
                break;
            }
        }
        assert(~pos);
        for (int j = 1; j <= cnt + 1; j++) swap(mat[i][j], mat[pos][j]);
        for (int j = i + 1; j <= cnt; j++) {
            int iv = -1ll * mat[j][i] * binpow(mat[i][i], mod - 2) % mod;
            for (int k = i; k <= cnt + 1; k++) {
                mat[j][k] = (1ll * iv * mat[i][k] + mat[j][k]) % mod;
            }
        }
    }
    for (int i = cnt; i >= 1; i--) {
        for (int j = i + 1; j <= cnt; j++) {
            mat[i][cnt + 1] = (-1ll * mat[i][j] * res[j] + mat[i][cnt + 1]) % mod;
        }
        res[i] = 1ll * mat[i][cnt + 1] * binpow(mat[i][i], mod - 2) % mod;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            a[i][j] = (s[j - 1] == 'B');
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            b[i][j] = (s[j - 1] == 'B');
        }
    }
    dfs(1, m, 0);
    assert(mp[0] == 1);
    mat[1][1] = 1; mat[1][cnt + 1] = 0;
    iv = binpow(n * m * 2, mod - 2);
    for (int i = 2; i <= cnt; i++) {
        mat[i][i] = 1;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                for (int r = 0; r < 2; r++) {
                    for (int s = 1; s <= n; s++) {
                        for (int t = 1; t <= ap[i][s]; t++) c[s][t] = 2;
                        for (int t = ap[i][s] + 1; t <= m; t++) c[s][t] = b[s][t];
                    }
                    for (int s = 1; s <= j; s++) {
                        for (int t = 1; t <= k; t++) {
                            c[s][t] = r;
                        }
                    }
                    int id = get(c);
                    mat[i][id] = (mat[i][id] - iv) % mod;
                    mat[i][cnt + 1] = (1ll * iv * (j * k) + mat[i][cnt + 1]) % mod;
                }
            }
        }
    }
    gauss();
    printf("%d\n", (res[get(a)] + mod) % mod);
    return 0;
}