#include <iostream>

int n, m;
long long k;
int p[1000007];
int t[1000007];
int c[1000007];
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    p[x] = i;
  }
  for (int i = 2; i <= n; ++i) {
    // p[i - 1] -> p[i]
    int l = p[i - 1], r = p[i];
    if (l > r) std::swap(l, r);
    ++t[l], --t[r];
  }
  for (int i = 1; i < n; ++i) ++c[t[i] += t[i - 1]];
  for (int i = n - 1; i >= 0; --i) {
    while (c[i]--) t[++m] = i;
  }
  for (int i = 1; i < n; ++i) {
    k -= t[i];
    if (k <= 0) {
      std::cout << i << '\n';
      return 0;
    }
  }
  std::cout << "-1\n";
  return 0;
}
