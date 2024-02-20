#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
const double Pi = acos(-1.0);   // Pi
const double eps = 1e-2;    // 精度
longint n, m, ans;
double gcd(double a, double b)
{
    if (fabs(b) < eps)
        return a;
    if (fabs(a) < eps)
        return b;
    return gcd(b, fmod(a, b));
}
struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    friend double operator & (Point A, Point B)
    {
        return sqrt( (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) );
    }
} A, B, C;
double triangleArea, a, b, c, p, r;
double angleA, angleB, angleC, t;
int main()
{
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    a = B & C;
    b = A & C;
    c = A & B;
    p = (a + b + c) / 2.0;
    triangleArea = sqrt(p * (p - a) * (p - b) * (p - c));
    r = a * b * c / (4.0 * triangleArea);
    angleA = acos(1 - (a * a) / (2 * r * r));
    angleB = acos(1 - (b * b) / (2 * r * r));
    // angleC = acos(1 - (c * c) / (2 * r * r));
    angleC = 2 * Pi - angleA - angleB;
    t = gcd(angleA, gcd(angleB, angleC));
    cout << fixed << setprecision(6) << Pi * r * r * sin(t) / t << endl;
    return 0;
}