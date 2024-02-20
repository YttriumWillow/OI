#include <bits/stdc++.h>
#include <windows.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

int T;

void ChangeColor(int col) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col); }

void printcol(const char* s, int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

/*
0 = 黑色 8 = 灰色
1 = 蓝色 9 = 淡蓝色
2 = 绿色 10 = 淡绿色
3 = 浅绿色 11 = 淡浅绿色
4 = 红色 12 = 淡红色
5 = 紫色 13 = 淡紫色
6 = 黄色 14 = 淡黄色
7 = 白色 15 = 亮白色
*/


int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 14);
	printf("Test Cases Number: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7);
	
	scanf("%d", &T);
	
	printf("\n");
	
	int cnt = 0;
	for (int i = 1; i <= T; ++i)
	{
		
		system("gen.exe > in.txt");
        system("std.exe < in.txt > ans.txt");

        double beginTime = clock();

        system("sol.exe < in.txt > out.txt");

        double endTime = clock();

        double useTime = endTime - beginTime;
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
		int p = system("fc out.txt ans.txt");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7);
		
        if (p)
		{
        	printf("Test Case #%d ", i);
			printcol("Wrong Answer", 4);
			printf(", Running Time: %.1lfms\n", useTime);
        	break;
		}
		else
		{
			printf("Test Case #%d ", i);
			printcol("Accepted", 10);
			printf(", Running Time: %.1lfms\n", useTime);
			++cnt;
		}
		
		printf("\n\n");
	}
	
	printf("\n\n");
	
	
	
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 14);
	printf("For All %d Test Cases, AC %d of them.\n\n", T, cnt); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7);
	
    return 0;
}
