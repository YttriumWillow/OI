#include <iostream>

#include <queue>
#include <ctime>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;
int a[10010], b[10010], c[10010];

priority_queue<int, vector<int>, greater<int>> q;

int f(int i, int x)
{
    return a[i] * x * x + b[i] * x + c[i];
}

int main()
{
    // auto f = [](int i, int x) { return a[i] * x * x + b[i] * x + c[i]; };
	srand(time(0));
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j * j <= m * (rand() % m / 30 + 1); ++j)
            q.push(f(i, j));
    // for (reg int j = 1; j <= m; ++j)
        // q.push(f(i, j));
    for (reg int i = 1; i <= m && !q.empty(); ++i)
        printf("%d ", q.top()), q.pop();
    return 0;
}