#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define lc (k<<1)
#define rc (k<<1|1)
#define mid ((l+r)>>1)
#define LL lc,l,mid
#define RR rc,mid+1,r
typedef long long ll;
using namespace std;
constexpr int N=1e6+105;
 
inline int rd(){
	int r=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) r=r*10+(c^48),c=getchar();
	return r;
}
 
int n,m,k,lx[N],ly[N],mx,my,lnx[N];
int tt,tot;
 
struct sl{
	int l,r,y,v;
	bool operator<(const sl &o){return y<o.y;};
}ln[N<<1];
 
struct tree{int sum;ll len;}tr[N<<2];
 
void build(int k,int l,int r){
	tr[k].len=tr[k].sum=0;
	if(l==r) return;
	build(LL);build(RR);
}
 
inline void pushup(int k,int l,int r){
	if(tr[k].sum) tr[k].len=lnx[r+1]-lnx[l];
	else tr[k].len=tr[lc].len+tr[rc].len;
}
 
void modify(int k,int l,int r,int x,int y,int c){
	if(lnx[r+1]<=x || lnx[l]>=y) return;
	if(x<=lnx[l] && lnx[r+1]<=y){
		tr[k].sum+=c;pushup(k,l,r);
		return;
	}
	modify(LL,x,y,c);modify(RR,x,y,c);
	pushup(k,l,r);
}
 
int main(){
	//cerr<<(&ED-&ST)/1024.0/1024.0<<'\n';
	n=rd(),m=rd(),k=rd();
	rep(i,1,max(m,n)) lx[i]=n+1;
	rep(i,1,max(m,n)) ly[i]=m+1;
	rep(i,1,k){
		int x=rd(),y=rd();
		lx[y]=min(lx[y],x),ly[x]=min(ly[x],y);
	}
	rep(i,1,lx[1]-1){
		++tot;
		ln[tot*2-1]={i,i+1,1,1};
		ln[tot*2]={i,i+1,ly[i],-1};
		lnx[tot*2-1]=i,lnx[tot*2]=i+1;
		//printf("r %d: %d %d %d %d\n",tot,i,i+1,1,ly[i]);
	}
	rep(i,1,ly[1]-1){
		++tot;
		ln[tot*2-1]={1,lx[i],i,1};
		ln[tot*2]={1,lx[i],i+1,-1};
		lnx[tot*2-1]=1,lnx[tot*2]=lx[i];
		//printf("r %d: %d %d %d %d\n",tot,1,lx[i],i,i+1);	
	}
	tot<<=1;
	sort(ln+1,ln+tot+1),sort(lnx+1,lnx+tot+1);
	tt=unique(lnx+1,lnx+1+tot)-lnx-1;
	build(1,1,tt-1);
	
	ll ans=0;
	for(int i=1;i<tot;++i){
		modify(1,1,tt-1,ln[i].l,ln[i].r,ln[i].v);
		ans+=tr[1].len*(ln[i+1].y-ln[i].y);
	}
	printf("%lld",ans);
	return 0;
}
 