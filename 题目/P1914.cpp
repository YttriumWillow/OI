#include <bits/stdc++.h>
#define longint long long
using namespace std;
char c[100]; 
longint n;
int main()
{
    scanf("%d %s", &n, c);
    for (int i = 0; c[i] != '\0'; i++)
        putchar( ( c[i]-'a' + n ) % 26 + 'a');
    return 0;
}
