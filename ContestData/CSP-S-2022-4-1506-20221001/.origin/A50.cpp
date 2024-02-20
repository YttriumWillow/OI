#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, q, m, ks, ans, a;
int t[100000000];
int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            t[i * j]++;
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> a;
        for (int j = 1; j <= 100000000; j++) {
            a -= t[j];
            if (a <= 0) {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
