#include <bits/stdc++.h>
using namespace std;
#define f64 double 
#define ls p << 1
#define rs p <<1 | 1
const int N = 1e5 + 5;
int n, m; f64 Tan[N];
struct Nd { int l, r, len; f64 max; } t[N * 4];
void update(int p) { t[p].max = max(t[ls].max, t[rs].max); }
int push_up(int p, f64 val) {
    if (t[p].max <= val) return 0; // 剪枝
    // if (Tan[t[p].l] > val) return t[p].len;
    if (t[p].l == t[p].r) return t[p].max > val;// ? t[p].len : 0; // 叶子节点
    if (t[ls].max <= val/*t[rs].max*/)
        return push_up(rs, val); // l_Mx >= r_Mx 递归左子树 
    return t[p].len - t[ls].len + push_up(ls, val); // 递归左子树大于x的部分 右子树的答案是重复贡献的
}
void build(int p, int l, int r) {
    t[p].l = l; t[p].r = r;
    if (l == r) { t[p].max = 0.0; t[p].len = 0; return; }
    int mid = l + r >> 1;
    build(ls, l, mid); build(rs, mid + 1, r);
    update(p); t[p].len = t[ls].len + push_up(rs, t[ls].max);
}
void modify(int p, int l, int r, f64 val) {
    if (t[p].l == t[p].r) { t[p].max = val; t[p].len = 1; return; }
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid) modify(ls, l, r, val);
    if (mid < r) modify(rs, l, r, val);
    update(p); t[p].len = t[ls].len + push_up(rs, t[ls].max);
}
signed main() {
    scanf("%d%d", &n, &m);
    build(1, 1, 1e5);
    for (int i = 1; i <= m; i++) {
        int val, y; scanf("%lld%lld", &val, &y);
        Tan[i] = 1.0 * y / val;
        modify(1, val, val, Tan[i]);
        printf("%d\n", t[1].len);
    }
}