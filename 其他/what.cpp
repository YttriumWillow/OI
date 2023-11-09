#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
//#define LL_inf 1145141919810
#define ull unsigned long long
#define ll long long
using namespace std;
//#define int long long
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<10)
	{
		putchar(x+'0');
		return ;
	}
	write(x/10);
	putchar(x%10+'0');
}
const int Maxn=4e5+10;
int n,m;
int son[Maxn],siz[Maxn];
int Top[Maxn],dfn[Maxn];
int dep[Maxn],fat[Maxn];
int dfsTime;
int head[Maxn],tot;
struct Edge{
	int to;
	int nxt;
}E[Maxn<<1];
void addedge(int u,int v)
{
	tot++;
	E[tot].to=v;
	E[tot].nxt=head[u];
	head[u]=tot;
}
void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	fat[u]=fa;
	siz[u]=1;
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].to;
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])
		{
			son[u]=v;
		}
	}
}
void dfs2(int u,int tp)
{
	Top[u]=tp;
	dfn[u]=++dfsTime;
	if(!son[u])
	{
		return ;
	}
	dfs2(son[u],tp);
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].to;
		if(v==fat[u] || v==son[u])
		{
			continue;
		}
		dfs2(v,v);
	}
}
int root[Maxn<<5];
struct SegTree
{
    int tot = 0;
    struct Node { int ls, rs, v; } t[Maxn << 5];
    inline int newNode() { return ++tot; }
    inline void pushup(int p) { Node &T = t[p]; T.v = t[T.ls].v + t[T.rs].v; }
    inline void update(int &p, int l, int r, int pos)
    {
        if (!p) { p = newNode(); } Node &T = t[p]; ++T.v;
        if (l == r) { return; }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(T.ls, l, mid, pos);
        if (mid  < pos) update(T.rs, mid + 1, r, pos);
    }
    inline int delet(int &p, int l, int r, int ql, int qr)
    {
        if (!p) { return 0; } Node &T = t[p];
        if (ql <= l and r <= qr) { p = 0; return T.v; }
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) res += delet(T.ls, l, mid, ql, qr);
        if (mid  < qr) res += delet(T.rs, mid + 1, r, ql, qr);
        pushup(p); if (!T.v) p = 0;
        return res;
    }
    inline int query(int &p, int l, int r, int ql, int qr)
    {
        if (!p) { return 0; } Node &T = t[p];
        if (ql <= l and r <= qr) { return T.v; }
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) res += query(T.ls, l, mid, ql, qr);
        if (mid  < qr) res += query(T.rs, mid + 1, r, ql, qr);
        return res;
    }
} seg;
/*
struct Segmenttree
{
    struct segtree { int ls, rs, v; } t[Maxn << 5];
    int totnum;
    int newnode() { return ++totnum; }
    void pushup(int p) { auto &T = t[p]; T.v = t[T.ls].v + t[T.rs].v; }
    void update(int &p, int l, int r, int pos)
    {
        if (!p) { p = newnode(); } auto &T = t[p]; 
        T.v++;
        if (l == r) { return ; }
        int mid = (l + r) >> 1;
        if (pos <= mid) { update(T.ls, l, mid, pos); }
        else { update(T.rs, mid + 1, r, pos); }
    }
    int delet(int &p, int l, int r, int ql, int qr)
    {
        if (!p) { return 0; } auto &T = t[p]; 
        int res = 0;
        if (ql <= l && r <= qr) { res = T.v; p = 0; return res; }
        int mid = (l + r) >> 1;
        if (ql <= mid) res += delet(T.ls, l, mid, ql, qr); 
        if (qr > mid) res += delet(T.rs, mid + 1, r, ql, qr); 
        pushup(p);
        if (!T.v) p = 0; 
        return res;
    }
    int query(int &p, int l, int r, int ql, int qr)
    {
        if (!p) return 0; auto &T = t[p]; 
        if (ql <= l && r <= qr) return T.v; 
        int mid = (l + r) >> 1, ans = 0;
        if (ql <= mid) ans += query(T.ls, l, mid, ql, qr); 
        if (qr > mid) ans += query(T.rs, mid + 1, r, ql, qr); 
        return ans;
    }
} seg;
*/
int queryedge(int &node,int u,int v)
{
	int ans=0;
	while(Top[u]!=Top[v])
	{
		if(dep[Top[u]]<dep[Top[v]])
		{
			swap(u,v);
		}
		ans+=seg.query(node,1,n,dfn[Top[u]],dfn[u]);
		u=fat[Top[u]];
	}
	if(dep[u]>dep[v])
	{
		swap(u,v);
	}
	ans+=seg.query(node,1,n,dfn[u],dfn[v]);
	return ans;
}
int deledge(int &node,int u,int v)
{
	int ans=0;
	while(Top[u]!=Top[v])
	{
		if(dep[Top[u]]<dep[Top[v]])
		{
			swap(u,v);
		}
		ans+=seg.delet(node,1,n,dfn[Top[u]],dfn[u]);
		u=fat[Top[u]];
	}
	if(dep[u]>dep[v])
	{
		swap(u,v);
	}
	ans+=seg.delet(node,1,n,dfn[u],dfn[v]);
	return ans;
}
int lca(int u,int v)
{
	while(Top[u]!=Top[v])
	{
		if(dep[Top[u]]<dep[Top[v]])
		{
			swap(u,v);
		}
		u=fat[Top[u]];
	}
	if(dep[u]>dep[v])
	{
		swap(u,v);
	}
	return u;
}
int main()
{
	n=read();
	m=read();
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	unordered_map<string,int> mp;
	int cnts=0;
	for(int i=1;i<=n;i++)
	{
		int nums;
		nums=read();
		while(nums--)
		{
			string str;
			cin>>str;
			if(mp[str]==0)
			{
				mp[str]=++cnts;
			}
			seg.update(root[mp[str]],1,n,dfn[i]);
		}
	}
	int tot=0;
	while(m--)
	{
		string str;
		cin>>str;
		if(str=="query")
		{
			string str2;
			cin>>str2;
			if(str2=="/p")
			{
				int u,v;
				u=read();
				v=read();
				int Lca=lca(u,v);
				write(dep[u]+dep[v]-2*dep[Lca]);
				putchar('\n');
			}else{
				int u,v;
				u=read(),v=read();
				string qaq;
				cin>>qaq;
				string tmp="";
				bool flags=0;
				for(int i=0;i<qaq.size();i++)
				{
					if(qaq[i]=='.')
					{
						flags=1;
						continue;
					}
					if(flags) tmp+=qaq[i];
				}
//				cout<<"tmp="<<tmp<<endl;
				if(mp[tmp]==0) puts("0");
				else{
					write(queryedge(root[mp[tmp]],u,v));
					putchar('\n');
				}
			}
		}else{
			string lrh;
			cin>>lrh;
			int u,v;
			u=read();
			v=read();
			string qaq;
			cin>>qaq;
			string tmp="";
			bool flags=0;
			for(int i=0;i<qaq.size();i++)
			{
				if(qaq[i]=='.')
				{
					flags=1;
					continue;
				}
				if(flags) tmp+=qaq[i];
			}
			if(mp[tmp]==0) puts("0");
			else{
				write(deledge(root[mp[tmp]],u,v));
				putchar('\n');
			}
		}
	}
	return 0;
}

