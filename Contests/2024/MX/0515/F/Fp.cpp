#include<bits/stdc++.h>
#define reg register
#define pb push_back

int read() {
    char c;
    int s = 0, flag = 1;
    while ((c = getchar()) && !isdigit(c))
        if (c == '-') { flag = -1, c = getchar(); break; }
    while (isdigit(c)) s = s * 10 + c - '0', c = getchar();
    return s * flag;
}

const int maxn = 200005;

int N;
int K;
int Q_;
int n1;
int n2;
int Lim;
int b_cnt;
int B[maxn];
int Mp[maxn];
int is[maxn];
int col[maxn];
int cnt[maxn];
int num[maxn];
int con[3004][3004];

std::vector <int> pos[maxn];

void calc(int x, int y) {
    if (is[x] && is[y]) n2++;
    if (!is[x] && is[y]) n2--;
    if (Mp[y]) {
        if (is[x]) num[y]++;
        else num[y]--;
    }
}

void fuck_1(int x) {
    is[x] ^= 1;
    if (is[x]) n1 += cnt[x];
    else n1 -= cnt[x];
    for (reg int i = pos[x].size() - 1; i >= 0; i--) {
        int c = pos[x][i];
        if (c < N) calc(col[c], col[c + 1]);
        if (c > 1) calc(col[c], col[c - 1]);
    }
}

void fuck_2(int x) {
    is[x] ^= 1;
    if (is[x]) n1 += cnt[x], n2 += num[x];
    else n1 -= cnt[x], n2 -= num[x];
    for (reg int i = 1; i <= b_cnt; i++) {
        int cur = B[i];
        if (cur == x || !is[cur]) continue;
        if (is[x]) n2 += con[Mp[x]][i];
        else if (!is[x]) n2 -= con[Mp[x]][i];
    }
}

void write(int x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    N = read(), Q_ = read(), K = read();
    for (reg int i = 1; i <= N; i++) scanf("%d", &col[i]);
    int tmp = 0;
    for (reg int i = 1; i <= N; i++) {
        while (i < N && col[i] == col[i + 1]) i++;
        col[++tmp] = col[i];
    }
    N = tmp; int Lim = 100;
    for (reg int i = 1; i <= N; i++) cnt[col[i]] ++, pos[col[i]].pb(i);
    for (reg int i = 1; i <= K; i++)
        if (cnt[i] > Lim)
            B[++b_cnt] = i, Mp[i] = b_cnt;
    for (reg int i = 1; i < N; i++)
        if (Mp[col[i]] && Mp[col[i + 1]])
            con[Mp[col[i]]][Mp[col[i + 1]]] ++, con[Mp[col[i + 1]]][Mp[col[i]]]++;
    while (Q_--) {
        int x;
        scanf("%d", &x);
        if (!Mp[x]) fuck_1(x);
        else fuck_2(x);
        printf("%d\n", n1 - n2);
    }
    return 0;
}
