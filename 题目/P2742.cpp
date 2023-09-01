#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sign(double d)
{
    if (fabs(d) < eps) return 0;
    return (d < 0.0) ? -1 : 1;
}
struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    friend Point operator - (Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
    friend Point operator + (Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
    friend double operator * (Point A, Point B) { return A.x * B.x + A.y * B.y; }   // 点积
    friend double operator ^ (Point A, Point B) { return A.x * B.y - A.y * B.x; }   // 叉积
    friend bool operator < (Point A, Point B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }    // sort
    friend bool operator == (Point A, Point B) { return sign(A.x - B.x) == 0 && sign(A.y - B.y) == 0; } // 去重用
    friend double operator & (Point A, Point B) { return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); } // 求长度
};
longint n, top;
double ans = 0.0;
Point p[100010];
Point st[200010];
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
        while (top && ((st[top] - st[top - 1]) ^ (p[i] - st[top])) < 0)
            --top;
        st[++top] = p[i];
    }
    // crashed here and down
    for (int i = n - 1; i > 0; i--)
    {
        while (top && ((st[top] - st[top - 1]) ^ (p[i] - st[top])) < 0)
            --top;
        st[++top] = p[i];
    }
    for (int i = 1; i < top; i++)
        ans += st[i - 1] & st[i];
    ans += st[top - 1] & st[0];

    printf("%.2lf\n", ans);
    return 0;
}