// Problem:       P2312 [NOIP2014 提高组] 解方程
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P2312
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-04-30 18:30:42 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 191981011451;

int n, m;
i64 a[100010];
vector<int> ans;

template<typename _Tp> 
inline void read(_Tp &x)
{
	x = 0; char ch = getchar(); _Tp sgn = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10 + (ch ^ 48)) % mod;
	x *= sgn;
}
template<typename _Tp>
inline void write(_Tp x)
{
    static char stk[40]; int top = 0;
    if (!x)     return putchar(48), void();
    if (x < 0)  putchar(45), x = -x;
    while (x)   stk[top++] = x % 10, x /= 10;
    while (top) putchar(stk[--top] + 48);
}
template<typename _Tp>
inline void writeln(_Tp x) { write(x); putchar('\n'); }

inline int QJS(int x)
{
	i64 res = 0;
	for (reg i64 i = n; i > 0; --i)
		res = (res + a[i]) * x % mod;
	res = (res + a[0]) % mod;
	return res;
}

int main()
{
	read(n); read(m);
	for (reg int i = 0; i <= n; ++i)
		read(a[i]);
	for (reg int i = 1; i <= m; ++i)
		if (QJS(i) == 0)
			ans.pb(i);
	writeln(ans.size());
	for (auto x : ans)
		writeln(x);
	return 0;
}