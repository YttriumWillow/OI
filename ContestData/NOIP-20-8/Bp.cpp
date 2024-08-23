#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-15;
const int N = 2e5 + 5;
int n;
long double sum;
long double a[N];
inline long double get(long double qwq) {
    if (qwq > sum / n) return 1e18;
    int l = 1, r = n;
    long double L = qwq, R = sum / n, now = sum, len = n - 1;
    while (len) {
        if ((now - a[r]) / len >= qwq) {
            now -= a[r]; len--; r--;
        }
        else {
            now -= a[l]; l++; len--;
            R = max(R, now / (len + 1));
        }
    }
    return R - L;
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], sum += a[i];
    long double M = sum / n, ans = 1e18;
    long double l = M - 1e9, r = M + 1e9;
    while ((r - l) > eps * l) {
        long double mid1 = (l * 2 / 3) + (r / 3), mid2 = (l / 3) + (r * 2 / 3);
        if (get(mid1) > get(mid2))l = mid1;
        else r = mid2;
    }
    ans = min(ans, get(l));
    l = 0, r = 1e18;
    while ((r - l) > eps * l) {
        long double mid1 = (l * 2 / 3) + (r / 3), mid2 = (l / 3) + (r * 2 / 3);
        if (get(mid1) > get(mid2))l = mid1;
        else r = mid2;
    }
    ans = min(ans, get(l));
    l = 0, r = 1e13;
    while ((r - l) > eps * l) {
        long double mid1 = (l * 2 / 3) + (r / 3), mid2 = (l / 3) + (r * 2 / 3);
        if (get(mid1) > get(mid2))l = mid1;
        else r = mid2;
    }
    ans = min(ans, get(l));
    l = M - 1e9, r = M + 1e8;
    while ((r - l) > eps * l) {
        long double mid1 = (l * 2 / 3) + (r / 3), mid2 = (l / 3) + (r * 2 / 3);
        if (get(mid1) > get(mid2))l = mid1;
        else r = mid2;
    }
    ans = min(ans, get(l));
    printf("%.10Lf", ans);
    return 0;
}