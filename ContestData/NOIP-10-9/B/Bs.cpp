#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int maxn = 4e5 + 5;
int n, m;
struct segment_tree {
    int tree[maxn << 2], tag[maxn << 2];
    void push_up(int p) { tree[p] = max(tree[p * 2], tree[p * 2 + 1]); }
    void push_down(int p, int l, int r) {
        tree[p * 2] += tag[p];
        tree[p * 2 + 1] += tag[p];
        tag[p * 2] += tag[p];
        tag[p * 2 + 1] += tag[p];
        tag[p] = 0;
    }
    void add(int p, int l, int r, int nl, int nr, int val) {
        if (l >= nl && r <= nr) {
            tag[p] += val;
            tree[p] += val;
            return;
        }
        push_down(p, l, r);
        int mid = (l + r) / 2;
        if (mid >= nl)
            add(p * 2, l, mid, nl, nr, val);
        if (mid < nr)
            add(p * 2 + 1, mid + 1, r, nl, nr, val);
        push_up(p);
    }
} T;
struct node {
    int l, r;
} q[maxn];
int l[maxn], r[maxn], tot;
bool cmp(node x, node y) {
    if (x.l == y.l)
        return x.r > y.r;
    return x.l < y.l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> q[i].l >> q[i].r;
    sort(q + 1, q + 1 + n, cmp);
    int maxr = 0;
    for (int i = 1; i <= n; i++) {
        if (maxr < q[i].r) {
            l[++tot] = q[i].l;
            r[tot] = q[i].r;
            maxr = q[i].r;
        }
    }
    for (int i = 1; i <= m; i++) {
        int p, x;
        cin >> p >> x;
        int nl = lower_bound(r + 1, r + 1 + tot, p) - r;
        int nr = upper_bound(l + 1, l + 1 + tot, p) - l - 1;
        if (nl <= nr)
            T.add(1, 1, tot, nl, nr, x);
        cout << T.tree[1] << endl;
    }
    return 0;
}
