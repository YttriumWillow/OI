#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define int long long
using namespace std;
const int N=1e6+5;
int ls[N],rs[N],fa[N];
int T,n,y[N];
struct node{
    int siz,pos;
}a[N];
void dfs(int u,int f){
    if(u==0) return;
    fa[u]=f;a[u].siz=1;
    dfs(ls[u],u);dfs(rs[u],u);
    a[u].siz+=a[ls[u]].siz;a[u].siz+=a[rs[u]].siz;
    a[u].pos=u;
}
bool cmp(node i,node j){
    return i.siz<j.siz;
}
void solve(){
    scanf("%lld",&n);
    ll ans=0,now=0,M=0;
    for(int i=1;i<=n;i++) fa[i]=ls[i]=rs[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&y[i]);
        ans+=y[i];
        if(i!=1) now+=abs(y[i]-y[i-1]);
    }
    M=y[1]+y[n];
    stack<int> st;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&y[i]>y[st.top()]){ls[i]=st.top();st.pop();}
        if(!st.empty()) rs[st.top()]=i;
        st.push(i);
    }
    int root=0;
    while(!st.empty()){root=st.top();st.pop();}
    dfs(root,0);
    sort(a+1,a+1+n,cmp);
    for(int u=1;u<=n&&M<now;u++){
        if((now-M)<=2*(y[fa[a[u].pos]]-y[a[u].pos])){
            ans+=(now-M)/2*a[u].siz;
            now-=(now-M);
        }
        else{
            now-=2*(y[fa[a[u].pos]]-y[a[u].pos]);
            ans+=(y[fa[a[u].pos]]-y[a[u].pos])*a[u].siz;    
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    // cout<<input_file<<endl;
    scanf("%lld",&T);
    while(T--) solve();
    return 0;
}