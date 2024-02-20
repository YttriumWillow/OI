// Problem:			P8823 [传智杯 #3 初赛] 期末考试成绩
// Contest:			Luogu
// URL:				https://www.luogu.com.cn/problem/P8823
// Memory Limit:	128 MB
// Time Limit:		1000 ms
// Created Time:	2023-02-19 10:22:54

#include <iostream>

#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    if (n >= 90)
        printf("%.1lf\n", 4.0);
    else if (n >= 60 && n < 90)
        printf("%.1lf\n", 4.0 - (90 - n) * 0.1);
    else if ((int)(sqrt(n) * 10) >= 60)
        n = (int)(sqrt(n) * 10),
        printf("%.1lf\n", 4.0 - (90 - n) * 0.1);
    else
    	printf("%.1lf\n", 0.0);
    return 0;
}