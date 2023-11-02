#include<bits/stdc++.h>
using namespace std;
#define ls pos<<1
#define rs pos<<1|1
const int N = 1e6 + 10;
struct Segment_Tree
{
	int l, r;
	int add, mx;
} tree1[N * 4], tree2[N * 4];
int n, m;
int a[N], b[N], c[N]; //b[i]={i,i+1} c[i]={i,i+1,i+2}
void update1(int pos)
{
	tree1[pos].mx = max(tree1[ls].mx, tree1[rs].mx);
}
void Build1(int pos, int l, int r)
{
	tree1[pos].l = l; tree1[pos].r = r;
	if (l == r)
	{
		tree1[pos].mx = b[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build1(ls, l, mid);
	Build1(rs, mid + 1, r);
	update1(pos);
}
void push_down1(int pos)
{
	if (tree1[pos].add)
	{
		int x = tree1[pos].add;
		tree1[pos].add = 0;
		tree1[ls].add += x;
		tree1[rs].add += x;
	}
	return;
}
void Add1(int pos, int l, int r, int c)
{
	if (l <= tree1[pos].l && tree1[pos].r <= r)
	{
		tree1[pos].mx += c;
		tree1[pos].add += c;
		return;
	}
	push_down1(pos);
	int mid = (tree1[pos].l + tree1[pos].r) >> 1;
	if (l <= mid) Add1(ls, l, r, c);
	if (r > mid)  Add1(rs, l, r, c);
	update1(pos);
}
int query1(int pos, int l, int r)
{
	if (l <= tree1[pos].l && tree1[pos].r <= r)
	{
		return tree1[pos].mx;
	}
	push_down1(pos);
	int mid = (tree1[pos].l + tree1[pos].r) >> 1;
	int cal = -1e9;
	if (l <= mid) cal = max(cal, query1(ls, l, r));
	if (r > mid)  cal = max(cal, query1(rs, l, r));
	update1(pos);
	return cal;
}


void update2(int pos)
{
	tree2[pos].mx = max(tree2[ls].mx, tree2[rs].mx);
}
void Build2(int pos, int l, int r)
{
	tree2[pos].l = l; tree2[pos].r = r;
	if (l == r)
	{
		tree2[pos].mx = c[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build2(ls, l, mid);
	Build2(rs, mid + 1, r);
	update2(pos);
}
void push_down2(int pos)
{
	if (tree2[pos].add)
	{
		int x = tree2[pos].add;
		tree2[pos].add = 0;
		tree2[ls].add += x;
		tree2[rs].add += x;
	}
	return;
}
void Add2(int pos, int l, int r, int c)
{
	if (l <= tree1[pos].l && tree1[pos].r <= r)
	{
		tree2[pos].mx += c;
		tree2[pos].add += c;
		return;
	}
	push_down2(pos);
	int mid = (tree2[pos].l + tree2[pos].r) >> 1;
	if (l <= mid) Add2(ls, l, r, c);
	if (r > mid)  Add2(rs, l, r, c);
	update2(pos);
}
int query2(int pos, int l, int r)
{
	if (l <= tree2[pos].l && tree2[pos].r <= r)
	{
		return tree2[pos].mx;
	}
	push_down2(pos);
	int mid = (tree2[pos].l + tree2[pos].r) >> 1;
	int cal = -1e9;
	if (l <= mid) cal = max(cal, query2(ls, l, r));
	if (r > mid)  cal = max(cal, query2(rs, l, r));
	update2(pos);
	return cal;
}
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n - 1; i++) b[i] = a[i] + a[i + 1];
	for (int i = 1; i <= n - 2; i++) c[i] = a[i] + a[i + 1] + a[i + 2];
	Build1(1, 1, n - 1); Build2(1, 1, n - 2);
	for (int i = 1; i <= m; i++)
	{
		int opt, l, r, x;
		scanf("%d%d%d", &opt, &l, &r);
		if (opt == 1)
		{
			scanf("%d", &x);
			if (l - 1 >= 1) Add1(1, l - 1, l - 1, x);
			if (r + 1 <= n) Add1(1, r, r, x);
			if (l - r + 1 >= 2)Add1(1, l, r - 1, x * 2);

			if (l - 2 >= 1) Add2(1, l - 2, l - 2, x);
			if (l - 1 >= 1) Add2(1, l - 1, l - 1, x * 2);
			if (r + 2 <= n) Add2(1, r, r, x);
			if (r + 1 <= n) Add2(1, r - 1, r - 1, x * 2);
			if (r - l + 1 >= 3) Add2(1, l, r - 2, x * 3);
		}
		else
		{
			int a = query1(1, l, r - 1), b = query2(1, l, r - 2);
			if (a >= b)
			{
				int s = gcd(a, 2);
				if (a != 0) printf("%d/%d\n", a / s, 2 / s);
				else puts("0/1");
			}
			else
			{
				int s = gcd(b, 3);
				if (b != 0) printf("%d/%d\n", b / s, 3 / s);
				else puts("0/1");
			}
		}
	}
}
