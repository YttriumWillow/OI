#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, t;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    vi a(n);
    rep(i, 0, n - 1) {
        cin >> a[i];
        a[i] %= t;
    }
    sort(ALL(a));
    a.resize(unique(ALL(a)) - a.begin());
    int ans = t;
    rep(i, 0, sz(a) - 1) {
        int d = a[i] - a[(i + 1) % sz(a)];

        if (d < 0)
            d += t;

        ans = min(ans, (d + 1) / 2);
    }
    cout << ans << endl;
    return 0;
}