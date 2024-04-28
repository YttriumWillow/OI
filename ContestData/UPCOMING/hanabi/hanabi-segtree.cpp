#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define rep(i, x) for (ll i = 0; i < x; i++)
#define rep1(i, x) for (ll i = 1; i <= x; i++)

const ll INF = 1000000000;

struct seg {
    ll siz;
    ll s[400010], t[400010], u[400010];
    void init (ll n) {
        siz = 1;
        while (siz < n)
            siz *= 2;
        rep (i, siz * 2 - 1) {
            s[i] = 0;
            t[i] = 0;
            u[i] = 0;
        }
    }
    void add (ll a, ll b, ll x, ll k, ll l, ll r) {
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b) {
            s[k] += x;
            t[k] += x;
            u[k] += x;
            return;
        }
        add (a, b, x, 2 * k + 1, l, (l + r) / 2);
        add (a, b, x, 2 * k + 2, (l + r) / 2, r);
        s[k] = min (s[2 * k + 1], s[2 * k + 2]) + t[k];
        u[k] = max (u[2 * k + 1], u[2 * k + 2]) + t[k];
    }
    void max0 (ll x, ll k, ll l, ll r) {
        if (u[k] < x) {
            s[k] += x - u[k];
            t[k] += x - u[k];
            u[k] += x - u[k];
        }
        if (s[k] >= x)
            return;
        if (t[k] != 0) {
            add (l, (l + r) / 2, t[k], 2 * k + 1, l, (l + r) / 2);
            add ((l + r) / 2, r, t[k], 2 * k + 2, (l + r) / 2, r);
            t[k] = 0;
        }
        max0 (x, 2 * k + 1, l, (l + r) / 2);
        max0 (x, 2 * k + 2, (l + r) / 2, r);
        s[k] = min (s[2 * k + 1], s[2 * k + 2]) + t[k];
        u[k] = max (u[2 * k + 1], u[2 * k + 2]) + t[k];
    }
    void comp () {
        rep (i, siz - 1) {
            s[2 * i + 1] += t[i];
            t[2 * i + 1] += t[i];
            u[2 * i + 1] += t[i];
            s[2 * i + 2] += t[i];
            t[2 * i + 2] += t[i];
            u[2 * i + 2] += t[i];
            t[i] = 0;
        }
    }
} seg;

int main () {
    static ll n, l;
    static ll t[100010], p[100010];
    scanf ("%lld%lld", &n, &l);
    rep (i, n) { scanf ("%lld%lld", &t[i], &p[i]); }

    seg.init (100010);
    ll k = 0;
    ll ret = 0;
    rep1 (i, 100000) {
        bool _t = false;
        while (k < n && t[k] == i) {
            seg.add (1, p[k] + 1, 1, 0, 0, seg.siz);
            seg.add (p[k] + 1, l + 1, -1, 0, 0, seg.siz);
            ret += p[k];
            k++;
            _t = true;
        }
        if (_t) seg.max0 (0, 0, 0, seg.siz);
    }
    seg.comp ();

    ll MAX = 0;
    ll sum = 0;
    rep1 (i, l) {
        sum += seg.s[i + seg.siz - 1];
        MAX = max (MAX, sum);
    }
    cout << ret - MAX << endl;
}
