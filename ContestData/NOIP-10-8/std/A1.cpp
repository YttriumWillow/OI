#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n;
ll k;
int p[maxn];
int pos[maxn];
template<class T>
T read(T& x)
{
	x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
int cha[maxn];
int cnt[maxn];
int main()
{
	read(n);
	read(k);
	for(int i=1;i<=n;i++)
	{
		read(p[i]);
		pos[p[i]]=i;
	}
	int now=pos[1];
	for(int i=2;i<=n;i++)
	{
		if(pos[i]>now)
		{
			cha[now]++;
			cha[pos[i]]--;
		}
		else
		{
			cha[pos[i]]++;
			cha[now]--;
		}
		now=pos[i];
	}
	for(int i=1;i<n;i++)
	{
		cha[i]+=cha[i-1];
		cnt[cha[i]]++;
	}
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		ll nd=k/ll(i);
		if(k%ll(i))nd++;
		k-=1ll*min(nd,1ll*cnt[i])*(ll)i;
		ans+=min(nd,1ll*cnt[i]);
		if(k<=0)break;
	}
	if(k>0)puts("-1");
	else printf("%d",ans);
	return 0;
}
