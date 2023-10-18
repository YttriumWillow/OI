#include<bits/stdc++.h>

using namespace std;

#include <cstring>
template<typename T>
inline void Radixsort(T *fst, T *lst, T *buf, int *op)
{
	static int b[0x100], i, j;
	int Len = lst - fst, Sz = sizeof(T), at = 0;
	unsigned char *bgn, *end, tmp;
	for (i = 0; i < Sz; ++i)
	{
		if (op[i] == -1) continue;
		bgn = (unsigned char*) fst + i;
		end = (unsigned char*) lst + i;
		tmp = ((op[i] & 1) ? 0xff : 0) ^ ((op[i] & 2) ? 0x80 : 0);
		memset(b, 0, sizeof(b));
		for (unsigned char *it = bgn; it != end; it += Sz) ++b[tmp ^ *it];
		for (j = 1; j < 0x100; ++j) b[j] += b[j - 1];
		for (unsigned char *it = end; it != bgn; buf[--b[tmp^ * (it -= Sz)]] = *--lst);
		lst = buf + Len; swap(fst, buf); at ^= 1;
	}
	if (at) memcpy(buf, fst, Sz * Len);
}
