#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>

// #define int int64_t

namespace iobuff {
const int LEN = 1000000;
char in[LEN + 5], out[LEN + 5];
char *pin = in, *pout = out, *ed = in, *eout = out + LEN;
inline char gc(void) {
  return pin == ed && (ed = (pin = in) + fread(in, 1, LEN, stdin), ed == in) ? EOF : *pin++;
}
inline void pc(char c) {
  pout == eout && (fwrite(out, 1, LEN, stdout), pout = out);
  (*pout++) = c;
}
inline void flush() { fwrite(out, 1, pout - out, stdout), pout = out; }
template <typename T>
inline void scan(T &x) {
  static int f;
  static char c;
  c = gc(), f = 1, x = 0;
  while (c < '0' || c > '9') f = (c == '-' ? -1 : 1), c = gc();
  while (c >= '0' && c <= '9') x = 10 * x + c - '0', c = gc();
  x *= f;
}
template <typename T>
inline void putint(T x, char div) {
  static char s[100];
  static int top;
  top = 0;
  x < 0 ? pc('-'), x = -x : 0;
  while (x) s[top++] = x % 10, x /= 10;
  !top ? pc('0'), 0 : 0;
  while (top--) pc(s[top] + '0');
  pc(div);
}
}  // namespace iobuff
using namespace iobuff;

const int kMaxN = 6e6 + 5, kMod = 1e9 + 7;

int n, ans;
int c[kMaxN], a[kMaxN], idx[3];
int f[kMaxN], g[kMaxN], lst[kMaxN];

inline void inc(int &x, int y) { (x += y) >= kMod ? (x -= kMod) : x; }

void work(int l, int r) {
  for (int i = 1; i <= n; ++i)
    lst[i] = 0;
  f[l - 1] = 0, g[l - 1] = 1;
  for (int i = l; i <= r; ++i) {
    int ff = 0, gg = 0;
    f[i] = f[i - 1], g[i] = g[i - 1];
    if (lst[c[i]]) {
      ff = f[lst[c[i]] - 1] + 1, gg = g[lst[c[i]] - 1];
      if (ff > f[i])
        f[i] = ff, g[i] = gg;
      else if (ff == f[i])
        inc(g[i], gg);
    }
    lst[c[i]] = i;
  }
  if (f[r] == n - 1) ans = (ans + g[r]) % kMod;
}

void dickdreamer() {
  scan(n);
  for (int i = 1; i <= 3 * n; ++i) {
    scan(c[i]);
    c[i + 3 * n] = c[i];
    if (c[i] != 1) continue;
    if (!idx[0]) {
      idx[0] = i;
    } else if (!idx[1]) {
      idx[1] = i;
    } else {
      idx[2] = i;
    }
  }
  work(idx[1] + 1, idx[0] + 3 * n - 1);
  work(idx[2] + 1, idx[1] + 3 * n - 1);
  work(idx[0] + 1, idx[2] - 1);
  std::cout << ans << '\n';
}

int32_t main() {
#ifdef ORZXKR
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  // std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}
