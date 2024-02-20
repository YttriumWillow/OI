#include<bits/stdc++.h>
using namespace std;

__int128_t a,b,c,aa[110],pA[1<<24|3],pB[1<<24|3];
int p[110],q[110],n,o[110],oN,yzN;
pair<__int128_t,int> yz[5000010];

__int128_t read()
{
	__int128_t p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

void getyz(int x,__int128_t nw,int m)
{
	if (x==n+1) {yz[++yzN]=make_pair(nw,m); return;}
	for (int i=0; i<=q[x]; i++,nw*=p[x]) getyz(x+1,nw,m|(i==q[x]?(1<<x-1):0));
}

int main()
{
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d%d",&p[i],&q[i]);
		aa[i]=p[i];
		for (int j=1; j<q[i]; j++) aa[i]=aa[i]*p[i];
	}
	yzN=0,getyz(1,1,0);
	assert(yzN<=5000000);
	a=read(),b=read();
	for (int i=1; i<=yzN; i++)
	{
		if (yz[i].first>=a&&(!pA[yz[i].second]||pA[yz[i].second]>yz[i].first)) pA[yz[i].second]=yz[i].first;
		if (yz[i].first>=b&&(!pB[yz[i].second]||pB[yz[i].second]>yz[i].first)) pB[yz[i].second]=yz[i].first;
	}
	for (int i=(1<<n)-1; i>=0; i--) 
		for (int j=0; j<n; j++) if (!((i>>j)&1))
		{
			if (!pA[i]||pA[i]>pA[i|(1<<j)]) pA[i]=pA[i|(1<<j)];
			if (!pB[i]||pB[i]>pB[i|(1<<j)]) pB[i]=pB[i|(1<<j)];
		}
	__int128_t ans=-1;
	for (int i=0; i<(1<<n); i++) 
		if (pA[i]&&pB[((1<<n)-1)^i])
			if (ans==-1||ans>pA[i]+pB[((1<<n)-1)^i])
				ans=pA[i]+pB[((1<<n)-1)^i];
	ans-=(a+b);
	oN=0;
	while (ans) o[++oN]=ans%10,ans/=10;
	if (!oN) o[oN=1]=0;
	for (int i=oN; i; i--) putchar(o[i]+48);putchar('\n');
	return 0;
}
