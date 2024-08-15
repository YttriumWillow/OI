#include <bits/stdc++.h>
#define db double
#define il inline
#define re register
#define ui unsigned
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
#define N 200005
il void chkmin(ll &x, ll y) {(x > y) && (x = y);}
int n, p[N], rk[N]; pii a[N];
ll s[N * 4], tag[N * 4];
il void pushup(int i) {
  s[i] = min(s[i << 1], s[i << 1 | 1]);
}
il void pushs(int i, ll w) {s[i] += w, tag[i] += w;}
il void pushdown(int i) {
  if(tag[i]) pushs(i << 1, tag[i]), pushs(i << 1 | 1, tag[i]), tag[i] = 0;
}
il void adds(int el, int er, ll w, int i, int l, int r) {
  if(el > er) return ; if(l >= el && r <= er) return pushs(i, w); int mid = l + r >> 1; pushdown(i);
  if(mid >= el) adds(el, er, w, i << 1, l, mid); if(mid < er) adds(el, er, w, i << 1 | 1, mid + 1, r);
  pushup(i);
}
il void upd(int x, ll w, int i, int l, int r) {
  if(l == r) {s[i] = min(s[i], w); return ;} int mid = l + r >> 1; pushdown(i);
  if(mid >= x) upd(x, w, i << 1, l, mid); else upd(x, w, i << 1 | 1, mid + 1, r);
  pushup(i);
}
il ll query(int el, int er, int i, int l, int r) {
  if(el > er) return 1e18; if(l >= el && r <= er) return s[i]; int mid = l + r >> 1; ll ans = 1e18; pushdown(i);
  if(mid >= el) ans = min(ans, query(el, er, i << 1, l, mid)); if(mid < er) ans = min(ans, query(el, er, i << 1 | 1, mid + 1, r));
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n; ll ans = 0;
  for(re int i = 1; i <= n; ++i)
    cin >> a[i].fi >> a[i].se, p[i] = i;
  sort(a + 1, a + 1 + n);
  sort(p + 1, p + 1 + n, [](int x, int y) {return a[x].se < a[y].se;});
  for(re int i = 1; i <= n; ++i) rk[p[i]] = i;
  for(re int i = 1; i <= n; ++i) {
    ll w = query(0, rk[i] - 1, 1, 0, n);
    upd(rk[i], w, 1, 0, n);
    adds(0, rk[i] - 1, a[i].se, 1, 0, n);
    adds(rk[i], n, a[i].fi, 1, 0, n);
  }
  cout << s[1];
}
