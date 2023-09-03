// Problem:       T326618 金盏花
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/T326618?contestId=106124
// Memory Limit:  512 MB
// Time Limit:    1000 ms
// Created Time:  2023-06-03 15:51:40 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 x, y, z, faq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> y >> z;
	faq = z % 1000000;
	if (y < faq)
		cout << (i64)1e11 + y - z << endl;
	else
	{
		// cout << z / 1000000 << endl;
		// cout << z - (z / 1000000 - 1) * 1000000 + y << endl;
		cout << min(z / 1000000 * 1000000 + y - z, 
		z - (z / 1000000 - 1) * 1000000 - y) << endl;
	}
	return 0;
}