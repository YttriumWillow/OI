#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 3e5 + 5;

i64 n, k, d, m, res, Maxd;
i64 a[N], b[N]; // 每日来袭量，今日+昨日处理后剩余敌袭

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n >> k;
    rep (i, 1, n) {
        std::cin >> d >> m; a[d] += m;
        Maxd = std::max(Maxd, d); // 额外统计最大天数
    }
    rep (i, 0, Maxd + 1) {
        if (b[i] > k) { // 昨日剩余敌袭
            b[i + 1] += a[i]; // 贪心策略：优先处理昨日剩余敌袭，今日留给明日
            res += k; // 答案统计弹药使用量
        } else { // 完全清理剩余敌袭
            i64 left = k - b[i]; // 今日剩余弹药
            res += b[i]; // 优先处理昨日剩余敌袭
            if (a[i] > left) { // 不能处理完今日
                b[i + 1] += a[i] - left; // 统统留到明天
                res += left; // 答案统计弹药使用量
            } else { // 可以处理完今日
                res += a[i]; // 答案统计弹药使用量
            }
        }
    }
    std::cout << res << '\n';
}