#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, win, lose;
char ch; string str;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
int main()
{
    while(1)
	{
        ch = getchar();
		if (ch == 'E' || ch == EOF)
			break;
		else if (ch != '\n')
			str += ch;
	}
    n = str.size();
    // ----------------------11----------------------
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'W')
            win++;
        if (str[i] == 'L')
            lose++;
        if ( (lose - win >= 2 || win - lose >= 2) && (win >= 11 || lose >= 11 ) )
        {
            printf("%d:%d\n", win, lose);
            win = lose = 0;
        }
    }
    printf("%d:%d\n\n", win, lose);
    win = lose = 0;
    // ----------------------21----------------------
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'W')
            win++;
        if (str[i] == 'L')
            lose++;
        if ( (lose - win >= 2 || win - lose >= 2) && (win >= 21 || lose >= 21 ) )
        {
            printf("%d:%d\n", win, lose);
            win = lose = 0;
        }
    }
    printf("%d:%d\n", win, lose);
    //qwq
    return 0;
}