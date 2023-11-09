#include <iostream>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;

int n, opt, x;

namespace ScapeGoatTree
{
const double ALPHA = 0.7; // 平衡因子 / 平衡指数
#define exist(p) !(t[p].cnt == 0 && t[p].ls == 0 && t[p].rs == 0)
struct Node
{
	int ls, rs;
	int val, cnt, siz;
	// value, rep value counts, subtree size
} t[N];
vector<int> FP, FN, FV;
int tot;

inline int flatten(int p) // 拍扁存入待重构序列
{
	Node& T = t[p];
	if (exist(T.ls)) flatten(T.ls);
	int id = FP.size();
	if (T.cnt != 0)
	{
		FP.push_back(p);
		FV.push_back(T.val);
		FN.push_back(T.cnt);
	}
	if (exist(T.rs)) flatten(T.rs);
	return id;
}

inline void rebuild(int p, int l = 0, int r = FP.size() - 1)
{
	Node& T = t[p];
	int mid = (l + r) >> 1, siz1 = 0, siz2 = 0;
	if (l < mid)
	{
		T.ls = FP[(l + mid - 1) / 2];
		rebuild(T.ls, l, mid - 1);
		siz1 = t[T.ls].siz;
	}
	else T.ls = 0;
	if (mid < r)
	{
		T.rs = FP[(mid + r + 1) / 2];
		rebuild(T.rs, mid + 1, r);
		siz2 = t[T.rs].siz;
	}
	else T.rs = 0;

	T.cnt = FN[mid];
	T.val = FV[mid];
	T.siz = siz1 + siz2 + T.cnt;
}

inline void restructure(int p)
{
	Node& T = t[p];
	if (max(t[T.ls].siz, t[T.rs].siz) > ALPHA * T.siz) // 大小失衡
	{
		FP.clear(); FV.clear(); FN.clear();
		int id = flatten(p);
		swap(FP[id], FP[(FP.size() - 1) / 2]); // 保证重构后节点不会改变
		rebuild(p);
	}
}

inline void insert(int v, int p = 1)
{
	Node& T = t[p];
	if (!exist(p)) { T.val = v; T.cnt = 1; }
	else if (v < T.val)
	{
		if (!exist(T.ls)) T.ls = ++tot;
		insert(v, T.ls);
	}
	else if (v > T.val)
	{
		if (!exist(T.rs)) T.rs = ++tot;
		insert(v, T.rs);
	}
	else ++T.cnt;
	++T.siz;
	restructure(p);
}
inline void del(int v, int p = 1)
{
	Node& T = t[p]; --T.siz;
	if (v < T.val)		del(v, T.ls);
	else if (v > T.val) del(v, T.rs);
	else 				--T.cnt;
	restructure(p);
}
inline int countl(int v, int p = 1)
{
	Node& T = t[p];
	if (v < T.val)		return exist(T.ls) ? countl(v, T.ls) : 0;
	else if (v > T.val)	return t[T.ls].siz + T.siz + (exist(T.rs) ? countl(v, T.rs) : 0);
	else 				return t[T.ls].siz;
}
inline int countg(int v, int p = 1)
{
	Node& T = t[p];
	if (v > T.val)		return exist(T.rs) ? countg(v, T.rs) : 0;
	else if (v < T.val)	return t[T.rs].siz + T.cnt + (exist(T.ls) ? countg(v, T.ls) : 0);
	else 				return t[T.rs].siz;
}
inline int rnk(int v) { return countl(v) + 1; }
inline int kth(int k, int p = 1)
{
	Node& T = t[p];
	if (t[T.ls].siz + 1 > k)			return kth(k, T.ls);
	else if (t[T.ls].siz + T.cnt < k)	return kth(k - t[T.ls].siz - T.cnt, T.rs);
	else 								return T.val;
}
inline int prv(int v) { int r = countl(v); return kth(r); }
inline int nxt(int v) { int r = t[1].siz - countg(v) + 1; return kth(r); }
} using namespace ScapeGoatTree;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--)
	{
		cin >> opt >> x;
		switch (opt)
		{
		case 1: insert(x);
			break;
		case 2: del(x);
			break;
		case 3: cout << rnk(x) << endl;
			break;
		case 4: cout << kth(x) << endl;
			break;
		case 5: cout << prv(x) << endl;
			break;
		case 6: cout << nxt(x) << endl;
			break;
		}
	}


	return 0;
}