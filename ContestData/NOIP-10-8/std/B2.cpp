#include<bits/stdc++.h>
#define add(x, y) (x + y >= mod ? x + y - mod : x + y)
using namespace std;
const int maxn = 6000005, mod = 1e9 + 7;
int n;
int c[maxn];
int lst[maxn];
int dp[maxn], f[maxn];
vector<int> p;
int ans;
void work(int x, int y) {
    if (x < y) x += 3 * n;
    x--;
    for (int i = 1; i <= n; i++) lst[i] = 0;
    dp[y] = 1, f[y] = 0;
    for (int i = y + 1; i <= x; i++) {
        if (lst[c[i]]) {
            int k = lst[c[i]] - 1;
            if (f[k] + 1 == f[i - 1]) dp[i] = add(dp[k], dp[i - 1]);
            else if (f[k] + 1 < f[i - 1]) dp[i] = dp[i - 1];
            else dp[i] = dp[k];
            f[i] = max(f[k] + 1, f[i - 1]);
        }
        else dp[i] = dp[i - 1], f[i] = f[i - 1];
        lst[c[i]] = i;
    }
    if (f[x] == n - 1) ans = (ans + dp[x]) % mod;
}
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
int main() {
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);
    scan(n);
    for (int i = 1; i <= 3 * n; i++) {
        scan(c[i]);
        if (c[i] == 1) p.push_back(i);
        c[i + 3 * n] = c[i];
    }
    work(p[0], p[1]);
    work(p[1], p[2]);
    work(p[2], p[0]);
    putint(ans, '\n');
    flush();
    // cerr << clock() * 1. / 1000 << endl;
    return 0;
}
