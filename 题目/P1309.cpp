/*
    FileName: P_1309_NOIP_2011_普及组_瑞士轮.cpp
        + randomhash: 4d94d678d8c8687624fa14aa
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2022/10/26 星期三
    Time: 20:14:50
        + Unix Timestamp(second): 1666786490
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

int n, k, q, s;
struct Ctr
{
    int num, grade, shili;
} a[200010], b[100010], c[100010];
bool cmp(Ctr a1, Ctr a2)
{
    if (a1.grade == a2.grade) return a1.num < a2.num;
    return a1.grade > a2.grade;
}
void fzy_work()
{
    int lb = 0, lc = 0, la;
    for (int i = 1; i < n * 2; i += 2)
    {
        if (a[i].shili > a[i + 1].shili)
        {
            a[i].grade++;
            b[++lb] = a[i];
            c[++lc] = a[i + 1];
        }
        else
        {
            a[i + 1].grade++;
            b[++lb] = a[i + 1];
            c[++lc] = a[i];
        }
    }
    lb = 1; lc = 1; la = 1;
    while (lb <= n && lc <= n)
    {
        if (cmp(b[lb], c[lc]))
            a[la++] = b[lb++];
        else a[la++] = c[lc++];
    }
    while (lb <= n)
        a[la++] = b[lb++];
    while (lc <= n)
        a[la++] = c[lc++];
}
int main()
{
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i <= n * 2; ++i)
        a[i].num = i, scanf("%d", &a[i].grade);
    for (int i = 1; i <= n * 2; ++i)
        scanf("%d", &a[i].shili);
    sort(a + 1, a + n * 2 + 1, cmp);
    for (int i = 1; i <= k; ++i)
        fzy_work();
    printf("%d", a[q].num);
    return 0;
}
