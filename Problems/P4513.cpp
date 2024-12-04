// Problem:      GSS3 - Can you answer these queries III
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP1716
// Memory Limit: 1 MB
// Time Limit:   330000 ms
// Created Time: 2023-08-17 11:04:19 

#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 5e5 + 5;

int n, q, c, a[N];

class SGT {
private:
#define ls(u) (u << 1)
#define rs(u) (u << 1 | 1)
	static constexpr int N = ::N << 2;
	int rt, st, ed;
	int sum[N], L[N], R[N], val[N];
	void upPush(int u) {
		sum[u] = sum[ls(u)] + sum[rs(u)];
		L[u] = std::max(L[ls(u)], sum[ls(u)] + L[rs(u)]);
		R[u] = std::max(R[rs(u)], sum[rs(u)] + R[ls(u)]);
		val[u] = std::max(R[ls(u)] + L[rs(u)], std::max(val[ls(u)], val[rs(u)]));
	}
	void build(int u, int l, int r) {
		if (l == r) return sum[u] = L[u] = R[u] = val[u] = a[l], void();
		int mid = l + r >> 1;
		build(ls(u), l, mid); build(rs(u), mid + 1, r);
		upPush(u);
	}
	void modifySet(int u, int l, int r, int pos, int k) {
		if (l == r) return sum[u] = L[u] = R[u] = val[u] = k, void();
		int mid = l + r >> 1;
		if (pos <= mid) modifySet(ls(u), l, mid, pos, k); 
		if (mid  < pos) modifySet(rs(u), mid + 1, r, pos, k);
		upPush(u);
	}
	std::array<int, 4> query(int u, int l, int r, int ql, int qr) {
		if (ql <= l and r <= qr) return { sum[u], L[u], R[u], val[u] };
		int mid = l + r >> 1;
		if (qr <= mid) return query(ls(u), l, mid, ql, qr);
		else if (mid <  ql) return query(rs(u), mid + 1, r, ql, qr);
		std::array<int, 4> lll = query(ls(u), l, mid, ql, qr);
		std::array<int, 4> rrr = query(rs(u), mid + 1, r, ql, qr);
		return {
			// 0-sum 1-L 2-R 3-val
			lll[0] + rrr[0],
			std::max(lll[1], lll[0] + rrr[1]),
			std::max(rrr[2], rrr[0] + lll[2]),
			std::max(lll[2] + rrr[1], std::max(lll[3], rrr[3]))
		};
	}
public:
	SGT(int u, int l, int r) {
		rt = u; st = l; ed = r;
		build(rt, st, ed);
	} 
	void modifySet(int pos, int k) {
		modifySet(rt, st, ed, pos, k);
	}
	int query(int l, int r) {
		auto res = query(rt, st, ed, l, r);
		return res[3];
	}
};

int main() {
	file("chick");
	sync(false, nullptr);
	std::cin >> n >> q >> c;
	rep (i, 1, n) std::cin >> a[i];
	SGT T(1, 1, n);
	while (q--) {
		int o, l, r; std::cin >> o >> l >> r;
		if (o == 1) {
			T.modifySet(l, r);
		} else {
			if (l > r) std::swap(l, r);
			std::cout << T.query(l, r) << '\n';
		}
	}
	return 0;
}