#include <bits/stdc++.h>
#define longint long long
#define reg register
#define qwq puts("fzy qwq~");
using namespace std;
bitset<100000010> p;
int n, ans;
void prime(int n)
{
    ans = n - 1;
    // 埃氏筛的玄学 bitset 优化
    p.set(); // 全 true
    p[0] = p[1] = 0;
    for (reg int i = 2; i * i <= n; i++) // 埃筛爆跑
        if (p[i])
            for (int j = i << 1; j <= n; j += i)
                if (p[j] == 1)
                    p[j] = 0, ans--;
}
int main()
{
    scanf("%d", &n);
    prime(n);
    printf("%d\n", ans);
    return 0;
}