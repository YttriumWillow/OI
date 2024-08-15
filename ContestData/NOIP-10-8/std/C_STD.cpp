#include <cstdio>
#include <ctime>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f
const int N=200005;

namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

namespace SGT{
	#define ls (u<<1)
	#define rs (u<<1|1)
	ll mn[N<<2], tag[N<<2];
	inline void addp(int u, ll v)
	{
		mn[u]+=v;
		tag[u]+=v;
	}
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			addp(ls, tag[u]);
			addp(rs, tag[u]);
			tag[u]=0;
		}
	}
	inline void upt(int u)
	{
		mn[u]=std::min(mn[ls], mn[rs]);
	}
	void setp(int u, int l, int r, int p, ll v)
	{
		if(l==r) { mn[u]=v; return; }
		int mid=(l+r)>>1;
		pushdown(u);
		if(p<=mid) setp(ls, l, mid, p, v);
		else setp(rs, mid+1, r, p, v);
		upt(u);
	}
	void add(int u, int l, int r, int l1, int r1, int v)
	{
		if(l1<=l&&r<=r1) { addp(u, v); return; }
		int mid=(l+r)>>1;
		pushdown(u);
		if(l1<=mid) add(ls, l, mid, l1, r1, v);
		if(r1>mid) add(rs, mid+1, r, l1, r1, v);
		upt(u);
	}
	ll ask(int u, int l, int r, int l1, int r1)
	{
		if(l1<=l&&r<=r1) return mn[u];
		int mid=(l+r)>>1;
		pushdown(u);
		ll ret=INF;
		if(l1<=mid) ret=std::min(ret, ask(ls, l, mid, l1, r1));
		if(r1>mid) ret=std::min(ret, ask(rs, mid+1, r, l1, r1));
		return ret;
	}
}
using namespace SGT;
int n, a[N], b[N], lsha[N], lshb[N], p[N];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scan(a[i]), scan(b[i]), lsha[i]=a[i], lshb[i]=b[i];
	std::sort(lsha+1, lsha+n+1), std::sort(lshb+1, lshb+n+1);
	for(int i=1; i<=n; ++i)
	{
		a[i]=std::lower_bound(lsha+1, lsha+n+1, a[i])-lsha;
		b[i]=std::lower_bound(lshb+1, lshb+n+1, b[i])-lshb;
		p[a[i]]=b[i];
	}
	std::fill(mn, mn+4*n+5, INF);
	setp(1, 0, n, 0, 0);
	for(int i=1; i<=n; ++i)
	{
		ll v=ask(1, 0, n, 0, p[i]-1)+lsha[i];
		setp(1, 0, n, p[i], v);
		add(1, 0, n, 0, p[i]-1, lshb[p[i]]);
		if(p[i]<n) add(1, 0, n, p[i]+1, n, lsha[i]);
	}
	printf("%lld\n", mn[1]);
	fprintf(stderr, "time: %d\n", clock());
	return 0;
}
