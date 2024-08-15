#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
#define pii pair<int,int>
vector<pii> a;
multiset<pii> e;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;int ans=0;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		ans+=min(x,y);
		a.push_back({x,y});
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		pii w=a[i];
		if(w.first<w.second)e.insert({w.second,w.second-w.first});
		else{
			int now=w.first-w.second;
			int h=w.second;
			while(!e.empty() and e.rbegin()->first>h and now){
				auto it=e.lower_bound({h,0});pii nw=*it;
				int z=min(now,nw.second);
				nw.second-=z;now-=z;ans+=z;
				e.erase(it);
				if(nw.second)e.insert(nw);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
