// Problem:       P9196 [JOI Open 2016] 销售基因链
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P9196
// Memory Limit:  1 MB
// Time Limit:    1500 ms
// Created Time:  2023-08-05 11:38:12 

#define pragma nahida
#nahida GCC optimize(3)
#nahida GCC optimize("Ofast")
#pragma GCC target("abm,avx,avx2,avx512f,mmx,popcnt,sse,sse2,sse3,sse4,ssse3")

#include <bits/stdc++.h>

#define i64 long long 
#define u64 unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
namespace FastIO { static constexpr int SIZE = 1 << 21; char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf; inline void read(char& c) { for(c = gc(); !std::isgraph(c); c = gc()); } inline void read(char* s) { char c = gc(); for(; !std::isgraph(c); c = gc());for(; std::isgraph(c); c = gc()) *s++ = c; *s = 0; } inline void read(std::string& s) { s.clear(); char c = gc(); for(; !std::isgraph(c); c = gc()); for(; std::isgraph(c); c = gc()) s.push_back(c); } inline void pc(char c) { if(p3 - obuf == SIZE) fwrite(obuf, 1, SIZE, stdout), p3 = obuf; *p3++ = c; } inline void write(char c) { pc(c); } inline void write(const char* s) { while(*s) pc(*s), ++s; } inline void write(std::string s) { for(const char c : s) pc(c); } template<typename _Tp>inline void read(_Tp& x) { x = 0; char c = gc(); int f = 0; for(; !std::isdigit(c); c = gc()) f |= c == '-'; for(; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48); return f ? x = ~x + 1 : 1, void(); } template<typename _Tp>inline void write(_Tp x) { static int stk[40]; int tp = 0; if(!x) return pc('0'), void(); if(x < 0) pc('-'), x = ~x + 1; while(x) stk[++tp] = x % 10, x /= 10; while(tp) pc(stk[tp--] + '0'); } template<typename _Tp>inline void writesp(_Tp x) { write(x), pc(' '); } template<typename _Tp>inline void writeln(_Tp x) { write(x), pc('\n'); } template<typename _Tp, typename ...Args>inline void read(_Tp& x, Args& ...args) { read(x), read(args...); } template<typename _Tp, typename ...Args>inline void write(_Tp x, Args ...args) { write(x), write(args...); } template<typename _Tp, typename ...Args>inline void writesp(_Tp x, Args ...args) { writesp(x), writesp(args...); } template<typename _Tp, typename ...Args>inline void writeln(_Tp x, Args ...args) { writeln(x), writeln(args...); } inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); } }
using namespace FastIO;

const int N = 1e5 + 5;
const u64 base = 137;

int n, m;
string str[N], x, y;
pair<u64, u64> qry[N];
unordered_map<u64, bitset<N>> pre, suf;
unordered_map<u64, bool> p, q;

int main()
{
	read(n, m);
	for (int i = 1; i <= n; ++i)
		read(str[i]);
	for (int i = 1, l1, l2; i <= m; ++i)
	{
		read(x, y);
		u64 h1 = 0, h2 = 0;
		l1 = x.size(), l2 = y.size();
		x = '#' + x, y = '#' + y;
		for (int j = 1; j <= l1; ++j)
			h1 = h1 * base + x[j];
		for (int j = l2; j >= 1; --j)
			h2 = h2 * base + y[j];
		p[h1] = 1, q[h2] = 1;
		qry[i] = make_pair(h1, h2);
	}
	for (int i = 1, len; i <= n; ++i)
	{
		len = str[i].size(), str[i] = '#' + str[i];
		u64 h1 = 0, h2 = 0;
		for (int j = 1; j <= len; ++j)
		{
			h1 = h1 * base + str[i][j];
			h2 = h2 * base + str[i][len - j + 1];
			if (p[h1]) pre[h1].set(i);
			if (q[h2]) suf[h2].set(i);
		}
	}
	for (int i = 1; i <= m; ++i)
		writeln((pre[qry[i].first] & suf[qry[i].second]).count());
	flush();
	return 0;
}
