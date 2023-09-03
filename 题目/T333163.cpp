// Problem:	T333163 放假
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/T333163
// Memory Limit:	128 MB
// Time Limit:	500000 ms
// Created Time:	2023-04-30 13:03:22 

#include <iostream>

#include <random>
#include <ctime>

#define i64 long long 
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

mt19937 deviceseed(random_device{}());
mt19937 timeseed(time(0));
uniform_int_distribution<> rnd(114, 514); // 生成整数
uniform_real_distribution<> dis(1, 2); // 生成实数

int main()
{
	for (reg int i = 1; i <= 5; ++i)
		cout << rnd(deviceseed) << endl;
	cout << endl;
	for (reg int i = 1; i <= 5; ++i)
		cout << rnd(timeseed) << endl;
	return 0;
}