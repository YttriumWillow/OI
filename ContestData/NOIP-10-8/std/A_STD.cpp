#include <cstdio>
#include <algorithm>
const int N=1000005;
int n, k, a[N], p[N];

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

int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1, x; i<=n; ++i) scan(x), p[x]=i;
	for(int i=1; i<n; ++i)
	{
		int l=std::min(p[i], p[i+1]), r=std::max(p[i], p[i+1]);
		++a[l], --a[r];
	}
	for(int i=1; i<n; ++i) a[i]+=a[i-1];
	std::sort(a+1, a+n);
	int t=0;
	for(int i=n-1; ~i&&k>0; --i) ++t, k-=a[i];
	printf("%d\n", (t==n)?-1:t);
	return 0;
}
