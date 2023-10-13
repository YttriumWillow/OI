#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 100005;
int lowbit(int x) {return x & -x;}
int n, m, a[N], p[N]; bool cmp(int x, int y) {return a[x] < a[y];}
int c[N], size = 0;
void add(int x, int k) {for (size += k; x <= n; x += lowbit(x))c[x] += k;}
int getsum(int x) {int ans = 0; for (; x; x -= lowbit(x))ans += c[x]; return ans;}
struct ASK
{
	int l, r, p;
} ask[N]; const int block = 300;
bool mmp(ASK n1, ASK n2)
{
	if (n1.l / block != n2.l / block)return n1.l < n2.l;
	if ((n1.l / block) & 1)return n2.r < n1.r;
	return n1.r < n2.r;
}
ll ans[N];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		p[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	int tmp = a[p[1]]; a[p[1]] = 1;
	for (int i = 2, t = 1; i <= n; i++)
	{
		if (a[p[i]] != tmp)t++;
		tmp = a[p[i]]; a[p[i]] = t;
	}//离散化

	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &ask[i].l, &ask[i].r);
		ask[i].p = i;
	}
	sort(ask + 1, ask + m + 1, mmp); //莫队排序

	int l = ask[1].l, r = ask[1].l - 1; ll sum = 0;
	for (int i = 1; i <= m; i++)
	{
		int ql = ask[i].l, qr = ask[i].r;
		while (r < qr) {r++; sum += size - getsum(a[r]); add(a[r], 1);}
		while (l > ql) {l--; sum += getsum(a[l] - 1); add(a[l], 1);}
		while (r > qr) {add(a[r], -1); sum -= size - getsum(a[r]); r--;}
		while (l < ql) {add(a[l], -1); sum -= getsum(a[l] - 1); l++;}
		ans[ask[i].p] = sum;
	}
	for (int i = 1; i <= m; i++)printf("%lld\n", ans[i]);
	return 0;
}