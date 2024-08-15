#include<bits/stdc++.h>
#define int long long
using namespace std;
using namespace std;
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


int n,k,a[1000006],pos[1000006],num[1000006];
priority_queue<int,vector<int>,less<int> >q;
signed main(){
//	freopen("ex_ball3.in","r",stdin);
	scan(n);scan(k);
	for(int i=1;i<=n;i++){
		scan(a[i]);
		pos[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		num[min(pos[i],pos[i+1])]++;
		num[max(pos[i],pos[i+1])]--;
	}
	int nowat=0;
	for(int i=1;i<=n;i++){
		nowat+=num[i];
	//	cout<<num[i]<<' ';
		q.push(nowat);
	}
	int sum=0,cnt=0;
	while(!q.empty()){
		cnt++;
		
		sum+=q.top();q.pop();
		if(sum>=k) break;
		if(cnt==n) {
			int use=-1;
			putint(use,'\n');
			flush();
			return 0;
		}
	}
	putint(cnt,'\n');
	flush();
	return 0;
}
