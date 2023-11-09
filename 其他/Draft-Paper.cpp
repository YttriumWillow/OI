struct SegTree
{
    int tot = 0;
    struct Node { int ls, rs, v; } t[Maxn << 5];
    inline int newNode() { return ++tot; }
    inline void pushup(int p) { Node &T = t[p]; T.v = t[T.ls].v + t[T.rs].v; }
    inline void update(int &p, int l, int r, int pos)
    {
        if (!p) { p = newNode(); } Node &T = t[p]; T.v++;
        if (l == r) { return; }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(T.ls, l, mid, pos);
        else update(T.rs, mid + 1, r, pos);
    }
    inline int delet(int &p, int l, int r, int ql, int qr)
    {
        if (!p) { return 0; } Node &T = t[p];
        if (ql <= l and r <= qr) { p = 0; return T.v; }
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) res += delet(T.ls, l, mid, ql, qr);
        if (mid  < qr) res += delet(T.rs, mid + 1, r, ql, qr);
        pushup(p); if (!T.v) p = 0;
        return res;
    }
    inline int query(int &p, int l, int r, int ql, int qr)
    {
        if (!p) { return 0; } Node &T = t[p];
        if (ql <= l and r <= qr) { return T.v; }
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) query(T.ls, l, mid, ql, qr);
        if (mid  < qr) query(T.rs, mid + 1, r, ql, qr);
        return res;
    }
} seg;

struct Segmenttree
{
    struct segtree { int ls, rs, v; } t[Maxn << 5];
    int totnum;
    int newnode() { return ++totnum; }
    void pushup(int p) { auto &T = t[p]; T.v = t[T.ls].v + t[T.rs].v; }
    void update(int &p, int l, int r, int pos)
    {
        if (!p) { p = newnode(); } auto &T = t[p]; 
        T.v++;
        if (l == r) { return ; }
        int mid = (l + r) >> 1;
        if (pos <= mid) { update(T.ls, l, mid, pos); }
        else { update(T.rs, mid + 1, r, pos); }
    }
    int delet(int &p, int l, int r, int ql, int qr)
    {
        if (!p) { return 0; } auto &T = t[p]; 
        int res = 0;
        if (ql <= l && r <= qr) { res = T.v; p = 0; return res; }
        int mid = (l + r) >> 1;
        if (ql <= mid) res += delet(T.ls, l, mid, ql, qr); 
        if (qr > mid) res += delet(T.rs, mid + 1, r, ql, qr); 
        pushup(p);
        if (!T.v) p = 0; 
        return res;
    }
    int query(int &p, int l, int r, int ql, int qr)
    {
        if (!p) return 0; auto &T = t[p]; 
        if (ql <= l && r <= qr) return T.v; 
        int mid = (l + r) >> 1, ans = 0;
        if (ql <= mid) ans += query(T.ls, l, mid, ql, qr); 
        if (qr > mid) ans += query(T.rs, mid + 1, r, ql, qr); 
        return ans;
    }
} seg;