#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,L,a,b;
struct node{
    int type,pos;
}p[N];
bool cmp(node i,node j){
    return i.pos<j.pos;
}
void solve(){
    scanf("%lld%lld%lld%lld",&n,&L,&a,&b);
    for(int i=1;i<=n;i++){
        char s[5];
        scanf("%s",s);
        if(s[0]=='E'){
            scanf("%lld",&p[i].pos);
            p[i].type=0;
        }
        else{
            scanf("%lld",&p[i].pos);
            p[i].type=1;
        }
    }
    sort(p+1,p+1+n,cmp);
    int k=0;
    for(int i=1;i<=n;i++){
        if(i==1 || (p[i].type==0 && p[i-1].type==1)){
            k++;
        }
    }
    int ans=0;
    if(a<b){
        ans=(n-k)*a+max(0ll,(k-2))*min(a,b-a);
    }
    else{
        ans=(n-k)*b;
    }    
    printf("%lld\n",ans);
}
signed main(){
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);

        int T;
        scanf("%lld",&T);
        while(T--) solve();
    
    return 0;    
}