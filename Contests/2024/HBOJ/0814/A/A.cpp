#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout); std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 1e5 + 5;
constexpr int B = 317;

int n, m, a[N];
int len, b[N];
int ch, buc[N], h[N], rnk[N], buch[N];
i64 v1[N][B + 5], v2[N][B + 5];
std::vector<int> pos[N];

// 1e5 sqrt
// 
// 1) 出现次数大于 sqrt n 那么该类最多只有 sqrt n 个
// 2) 出现次数小于 sqrt n 那么这类暴力很快？
// 
// ① 查询 2) 2) 对出现的位置进行暴力 单次 sqrt n
// ② 查询 1) *) 预处理 n sqrt n 查询常数

void discrete() {
    rep (i, 1, n) b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    len = std::unique(b + 1, b + n + 1) - b - 1;
    rep (i, 1, n) a[i] = std::lower_bound(b + 1, b + len + 1, a[i]) - b;
}

template<typename _Tp>
void upd(_Tp &x, _Tp y) { x = std::max(x, y); }

int main(/*int argc, char const* argv[]*/) {
    file("original");

    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i];
    discrete();

    rep (i, 1, n) ++buc[a[i]], pos[a[i]].push_back(i);
    rep (i, 1, len) if (buc[i] >= B) {
        h[++ch] = i; rnk[i] = ch;
    }
    rep (i, 1, n) {
        ++buch[a[i]];
        rep (j, 1, ch) upd(v1[a[i]][j], (i64)buch[a[i]] * (buc[h[j]] - buch[h[j]]));
    }
    std::fill(buch, buch + len + 1, 0);
    for (int i = n; i >= 1; --i) {
        ++buch[a[i]];
        rep (j, 1, ch) upd(v2[a[i]][j], (i64)buch[a[i]] * (buc[h[j]] - buch[h[j]]));
    }

    rep (i, 1, m) {
        int x, y; std::cin >> x >> y; i64 res = 0;
        x = std::lower_bound(b + 1, b + len + 1, x) - b;
        y = std::lower_bound(b + 1, b + len + 1, y) - b;

        if (x == y) {
            res = (i64)(buc[x] / 2) * (buc[x] - buc[x] / 2);
        }
        else if (buc[x] < B and buc[y] < B) {
            int cur = 0, cx = 0;
            for (auto i : pos[x]) { // sqrtn
                ++cx;
                while (cur < pos[y].size() and pos[y][cur] < i) ++cur;
                res = std::max(res, (i64)cx * (buc[y] - cur));
            }
        }
        else if (buc[x] >= B) { res = v2[y][rnk[x]]; }
        else if (buc[y] >= B) { res = v1[x][rnk[y]]; }

        std::cout << res << '\n';
    }



}