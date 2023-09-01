/*
    Name: PlaneGeometry.cpp
        + 中文名: 平面几何
        + base64: UGxhbmVHZW9tZXRyeS5jcHA=
        + md5: b190796a655d59c9a54daa1fa6a46a06
    Copyright: However it didn't exist.   :D
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/08/22
    Time: 16:57:37
        + Unix Timestamp(second): 1661158657
    Encoding: UTF-8
--->    + !!! Custom Tips: If there are !!!garbled characters!!!, please use utf-8 format to open. <---
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/
// 提示，自己打一遍有助于记忆
// 熟悉的火车头环节
#include <bits/stdc++.h>
// debug用
#define qwq(x) printf("qwq value: %d\n", x);
// long long 太长了看不习惯
#define longint long long
// double 有的时候太丑了
#define longfloat double
// register关键字，把修饰的变量塞到CPU的Cache中（一般认为是三级缓存）
// 好像C++14弃用了，但我测试还是会快一点
// 在1e9数据量声明为for循环变量执行空循环重复测10次求平均，加入270ms，不加400ms
#define reg register
// 快读模板
#define _read =read()
#define Vector Point
using namespace std;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') { sgn = -1; } ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
//
// 芜湖~火车头开完了



const double pi = acos(-1.0);  //高精度圆周率
const double eps = 1e-8;       //偏差值
const int maxp = 1010;         //点的数量
int sign(double x)  // 判断x是否等于0
{
    if (fabs(x) < eps)  return 0;
    else return x < 0 ? -1 : 1;
}
int Dcmp(double x, double y)    // 比较两个浮点数：0 相等；-1 小于；1 大于
{
    if (fabs(x - y) < eps) return 0;
    else return x < y ? -1 : 1;
}
class PlaneGeometry // 平面几何工具包
{
public:
    // 啊哈哈哈哈其实类里面可以套类
    class Point // 点类
    {
    public:
        double x, y;
        Point() { /* there's nothing */ }
        Point(double _x, double _y) : x(_x), y(_y) {} // 带值初始化
        Point operator + (Point B)
        {
            return Point(x + B.x, y + B.y);
        }
        Point operator - (Point B)
        {
            return Point(x - B.x, y - B.y);
        }
        Point operator * (double k) // 长度增大k倍
        {
            return Point(x * k, y * k);
        }
        Point operator / (double k) // 长度缩小k倍
        {
            return Point(x / k, y / k);
        }
        bool operator == (Point B)
        {
            return sign(x - B.x) == 0 && sign(y - B.y) == 0;
        }
        bool operator < (Point B)   // 用于凸包，如果点 A 在点 B 左下方或正下方 返回true
        {
            return sign(x - B.x) < 0 || (sign(x - B.x) == 0 && sign(y - B.y) < 0);
        }
    };
    // 关于矢量的方法
    double Dot(Vector A, Vector B)  // 点积
    {
        return A.x + B.x + A.y * B.y;
    }
    double Len(Vector A)    // 向量长度
    {
        return sqrt(Dot(A, A));
    }
    double LenSquare(Vector A)  // 向量长度的平方(保留精度)
    {
        return Dot(A, A);
    }
    double Angle(Vector A, Vector B)    // A和B向量的夹角
    {
        return acos(Dot(A, B) / Len(A) / Len(B));
    }
    double Cross(Vector A, Vector B)    // 叉积
    {
        return A.x * B.y - A.y * B.x;
    }
    Vector Normal(Vector A) // 向量 A 单位法向量
    {
        return Vector(-A.y / Len(A), A.x / Len(A));
    }
    bool Parallel(Vector A, Vector B)   // 向量是否平行或重合?
    {
        return sign(Cross(A, B)) == 0;
    }
    // 关于图形的方法
    double Area(Point A, Point B, Point C) // 三角形面积
    {
        return Cross(B - A, C - A) / 2.0;
    }
    double DoubleArea(Point A, Point B, Point C) // 双倍三角形面积(平行四边形)(保留精度)
    {
        return Cross(B - A, C - A);
    }
    double Distance(Point A, Point B)   // 两点距离 调用库函数
    {
        return hypot(A.x - B.x, A.y - B.y);
    }
    double DistancePythagoreanTheorem(Point A, Point B)   // 两点距离 勾股定理
    {
        return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    }
};
// 正文
int main()
{
    PlaneGeometry planegeometry;
    PlaneGeometry::Point X = PlaneGeometry::Point(3, 0);
    PlaneGeometry::Point Y = PlaneGeometry::Point(0, 4);
    cout << planegeometry.Distance(X, Y) << endl;
    return 0;
}
