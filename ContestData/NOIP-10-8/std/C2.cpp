/*
slow is fast
*/
#include<bits/stdc++.h>
#define pre(i,a,b) for(int i=a;i<=b;++i)
#define suf(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define pii pair<int,int>
using namespace std;
namespace io {
  #define iL (1 << 20)
  char ibuf[iL], *iS = ibuf + iL, *iT = ibuf + iL;
  #define gc() ((iS == iT) ? (iT = (iS = ibuf) + fread(ibuf, 1, iL, stdin), iS == iT ? EOF : *iS ++) : *iS ++)
  template<class T> inline void read(T &x) {
    x = 0;int f = 0;char ch = gc();
    for (;!isdigit(ch);f|=ch=='-',ch=gc());
    for (;isdigit(ch);x=(x*10) + (ch ^ 48), ch = gc());
    x = (f == 1 ? ~ x + 1 : x);
  }
  template<class T, class... Args> inline void read(T &x, Args&... args) { read(x), read(args...); }
  char Out[iL], *iter = Out;
  #define flush() fwrite(Out, 1, iter - Out, stdout), iter = Out
  template<class T> inline void write(T x, char ch = '\n') {
    T l, c[35];
    if (x < 0) *iter ++ = '-', x = ~ x + 1;
    for (l = 0; !l || x; c[l] = x % 10, l++, x /= 10);
    for (; l; -- l, *iter ++ = c[l] + '0');*iter ++ = ch;
    flush();
  }
  template<class T, class... Args> inline void write(T x, Args... args) { write(x, ' '), write(args...); }
}
using namespace io;
#define pii pair<int,int>
namespace Y {
const int N=2e5+5;
int n;
ll ans;
pii a[N];
multiset<pii> e;
vector<pii> wa,wb;
void MAIN() {
  read(n);
  pre(i,1,n) read(a[i].first,a[i].second);
  pre(i,1,n) ans+=min(a[i].first,a[i].second);
  sort(a+1,a+n+1);
  pre(i,1,n) {
    auto w=a[i];
    if(w.first<w.second) e.insert({w.second,w.second-w.first});
    else {
      int now=w.first-w.second,h=w.second;
      while(!e.empty()&&e.rbegin()->first>h&&now) {
        auto j=e.lower_bound({h,0});
        auto u=*j;
        int z=min(now,u.second);
        u.second-=z;now-=z;ans+=z;
        e.erase(j);
        if(u.second) e.insert(u);
      }
    }
  }
  cout<<ans<<endl;
}
};//namespace Y
signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) Y::MAIN();
	return 0;
}
