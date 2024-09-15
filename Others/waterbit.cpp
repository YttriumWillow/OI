#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read() {
    char ch = getchar(); ll x = 0, f = 1;
    while (ch < '0' || ch>'9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct node {
    int x, y;
}t[40404004];

struct nod {
    int x, y, id, w;
}a[20200222];


int tr[10000020];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    x++;
    while (x <= 10000010) {
        tr[x] += k;
        x += lowbit(x);
    }
}

int sum(int x) {
    x++;
    int s = 0;
    while (x) {
        s += tr[x];
        x -= lowbit(x);
    }
    return s;
}

bool cmp(node a, node b) {
    return a.x < b.x;
}

bool cmpp(nod a, nod b) {
    return a.x < b.x;
}

int ans[2020022];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        t[i].x = read(), t[i].y = read();
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {//询问矩阵拆成四个点
        int l = read(), r = read(), s = read(), t = read();
        cnt++; a[cnt].id = cnt; a[cnt].w = 1; a[cnt].x = s; a[cnt].y = t;
        cnt++; a[cnt].id = cnt; a[cnt].w = 1; a[cnt].x = s; a[cnt].y = r - 1;
        cnt++; a[cnt].id = cnt; a[cnt].w = 1; a[cnt].x = l - 1; a[cnt].y = t;
        cnt++; a[cnt].id = cnt; a[cnt].w = 1; a[cnt].x = l - 1; a[cnt].y = r - 1;
    }
    sort(t + 1, t + n + 1, cmp);//分别按 x 排序
    sort(a + 1, a + cnt + 1, cmpp);
    int now = 1;
    for (int i = 1; i <= cnt; i++) {//树状数组求逆序对
        while (t[now].x <= a[i].x && now <= n) {
            ;
            add(t[now].y, 1);
            now++;
        }
        ans[a[i].id] += sum(a[i].y);
    }
    for (int i = 1; i <= cnt; i += 4) {//容斥输出
        printf("%d\n", ans[i] - ans[i + 1] - ans[i + 2] + ans[i + 3]);
    }
    return 0;
}