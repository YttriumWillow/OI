#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int rd(){
    int x=0;
    char o=getchar();
    while(!isdigit(o)) o=getchar();
    while( isdigit(o)) x=(x<<1)+(x<<3)+(o-48),o=getchar();
    return x;
}
const int N=1e5+10,M=40,inf=1e9; 
int n,m,ans,k[6],box[6][N],_ans,sum[M],tmp[M];
int G[M][6],cnt[M],num,a[6];
void dfs(int x,int c){
    if(x==(1<<m)){
        c--;
        if(c==1||c==0) return ;
        num++; cnt[num]=c;
        for(int i=1;i<=c;i++)G[num][i]=a[i];
        return ;
    }
    if(c>5) return ;
    dfs(x+1,c);
    for(int i=1;i<=c;i++) if(a[i]&x) return ;
    a[c]=x;
    dfs(x+1,c+1);
    a[c]=0;
}
void read(){
    n=rd(); m=rd();
    memset(box,0,sizeof(box));
    for(int i=1;i<=m;i++){
        k[i]=rd();
        for(int j=1;j<=k[i];j++){
            int x;
            x=rd();
            box[i][x]=1;
        }
    }
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=1;j<=m;j++) x=((x<<1)|box[j][i]);
        sum[x]++;
    }
    memcpy(tmp,sum,sizeof(tmp));
}
namespace _1{//baoli
    int A[M],vis[M],ans;
    int check(){
        int _sum=0;
        memcpy(sum,tmp,sizeof(sum));
        for(int _=1;_<=num;_++){
            int i=A[_],Min=inf;
            for(int j=1;j<=cnt[i];j++)Min=min(Min,sum[G[i][j]]);
            for(int j=1;j<=cnt[i];j++)sum[G[i][j]]-=Min;
            _sum+=Min;
        }
        for(int i=1;i<(1<<m);i++) _sum+=sum[i];
        return _sum;
    }
    void dfs(int x){
        if(x==num+1){
            ans=min(ans,check());
            return ;
        }
        for(int i=1;i<=num;i++){
            if(vis[i])continue;
            vis[i]=1;
            A[x]=i;
            dfs(x+1);
            A[x]=0;
            vis[i]=0;
        }
    }
    void sol(){
        ans=inf;
        dfs(1);
        cout<<ans<<'\n';
    }
}
namespace _2{
    int A[M],w[M];
    const int mod=1e9+7;
    int check(){
        int _sum=0;
        memcpy(sum,tmp,sizeof(sum));
        for(int _=1;_<=num;_++){
            int i=A[_],Min=inf;
            for(int j=1;j<=cnt[i];j++)Min=min(Min,sum[G[i][j]]);
            for(int j=1;j<=cnt[i];j++)sum[G[i][j]]-=Min;
            _sum+=Min;
        }
        for(int i=1;i<(1<<m);i++) _sum+=sum[i];
        return _sum;
    }
    bool cmp(int i,int j){return w[i]<w[j];}
    void Rand(){
        for(int i=1;i<=num;i++) w[i]=(rand()+1)*(rand()+1)%mod*(rand()+1)%mod*(rand()+1)%mod*(rand()+1)%mod;
        for(int i=1;i<=num;i++) A[i]=i;
        sort(A+1,A+1+num,cmp);
        ans=min(ans,check());
    }
    void sol(){
        ans=inf;
        for(int i=1;i<=100000;i++) Rand();
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
  //  freopen("A.in","r",stdin);
   // freopen("A.out","w",stdout);
    srand(1030);
    read();
    dfs(1,1);
    if(m<=3) _1::sol();
    else _2::sol();
    return 0;
} 