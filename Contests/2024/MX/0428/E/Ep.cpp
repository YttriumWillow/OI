#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

int T;
int n;
string s;
bool st[200010][30][30];
bool st1[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> s;
        int cnt = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!st1[s[i] - 'a']) ++cnt;
            ans = 1ll * ans + 1ll * cnt;
            st1[s[i] - 'a'] = true;
        }
        printf("%lld\n", ans);
        memset(st1, false, sizeof(st1));
    }
    return 0;
}
