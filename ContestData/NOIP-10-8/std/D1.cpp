#include <bits/stdc++.h>
using namespace std;
namespace QYB {
  using ll = long long; const ll P = 1000000007ll;
  struct edge { int from, to, next; ll dis; } e[2000005];
  int n, tot = 1, f[500005]; vector<int> g[500005]; ll ans;
  int tag[2000005]; priority_queue<pair<ll, int> > q;
  int getf(int x) { return f[x] < 0? x: f[x] = getf(f[x]); }
  vector<pair<ll, pair<int, int> > > r;
  char getchar() {
    static char buf[1 << 25], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin)) == buf? EOF: *p1++;
  } ll read() {
    ll res = 0; char ch = getchar();
    while (ch < 48 || ch > 57) ch = getchar();
    while (ch >= 48 && ch <= 57) res = res * 10 + ch - 48, ch = getchar();
    return res;
  } void add_edge(int u, int v, ll w) {
    e[++tot] = {u, v, 0, w}; g[u].push_back(tot);
    if (v == u + 1 || v == 1 && u == n) q.emplace(-w, tot), tag[tot] = tag[tot ^ 1] = 1;
  } int main() {
    n = read(); ll ans = 0;
    for (int m = read(); m; m--) {
      ll u, v, w; u = read(); v = read(); w = read();
      add_edge(u, v, w); add_edge(v, u, w);
    } for (int i = 1; i <= n; i++) {
      sort(g[i].begin(), g[i].end(), [](int x, int y) { return e[x].to < e[y].to; });
      for (int j = 0; j < g[i].size(); j++) {
        e[g[i][j] ^ 1].next = g[i][(j + 1) % g[i].size()];
      }
    } while (true) {
      while (!q.empty() && tag[q.top().second] != 1) q.pop();
      if (q.empty()) break; int c = q.top().second ^ 1;
      q.pop(); tag[c] = tag[c ^ 1] = 2;
      for (int p = e[c].next; p != c; p = e[p].next) {
        e[p].dis += e[c].dis; e[p ^ 1].dis += e[c ^ 1].dis;
        if (tag[p] == 1) {
          tag[p] = tag[p ^ 1] = 2;
          r.push_back(make_pair(e[p].dis, make_pair(e[p].from, e[p].to)));
        } else if (tag[p] == 0) {
          tag[p] = tag[p ^ 1] = 1;
          q.emplace(-e[p].dis, p);
        }
      }
    } sort(r.begin(), r.end()); reverse(r.begin(), r.end());
    for (int i = 1; i <= n; i++) f[i] = -1;
    for (auto i: r) {
      int x = getf(i.second.first), y = getf(i.second.second);
      assert(x != y); (ans += 1ll * f[x] * f[y] % P * i.first % P) %= P;
      if (f[x] > f[y]) swap(x, y); f[x] += f[y]; f[y] = x;
    } return !printf("%lld\n", ans);
  }
} int main() { return QYB::main(); }
