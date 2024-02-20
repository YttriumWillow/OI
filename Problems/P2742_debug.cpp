#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (Point B)
    {
        if (x == B.x) return y < B.y;
        return x < B.x;
    }
} p[100010], st[100010];
longint n, top;
double ans = 0.0;
double cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}
double side(Point a, Point b, Point p)
{
    Point A = Point(b.x - a.x, b.y - a.y);
    Point B = Point(p.x - a.x, p.y - a.y);
    return cross(A, B);
}
double distance(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1);
    if (n < 3)
    {
        printf("-1\n");
        return 0;
    }
    st[0] = p[1];
    st[1] = p[2];
    top = 1;
    for (int i = 3; i <= n; i++)
    {
        while (top && side(st[top - 1], st[top], p[i]) <= 0)
            --top;
        st[++top] = p[i];
    }
    st[++top] = p[n - 1];
    for (int i = n - 2; i > 0; i--)
    {
        while (top && side(st[top - 1], st[top], p[i]) <= 0)
            --top;
        st[++top] = p[i];
    }
    for (int i = 2; i <= top; i++)
        ans += distance(st[i - 1], st[i]);
    ans += distance(st[1], st[top]);
    // for (int i = 1; i <= top; i++)
    //     printf("%lf %lf\n", st[i].x, st[i].y);
    printf("%.2lf", ans);
    return 0;
}