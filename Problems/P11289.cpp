#include <bits/stdc++.h>

#define i64 long long 
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c)

constexpr int N = 2e5 + 10;
int n, m;
int s[N], t[N];
typedef std::array<i64, 2> pll; // [0]endtime, [1]priter_id
typedef std::array<i64, 3> lll; // [0]start, [1]len, [2]task_id
lll task[N]; 
std::priority_queue<pll, std::vector<pll>, std::greater<pll>> wrk;
std::priority_queue<int, std::vector<int>, std::greater<int>> ava;
std::vector<i64> res[N];

int main() {
    sync(false, nullptr);
    std::cin >> n >> m;
    rep (i, 1, n) {
        int s, t; std::cin >> s >> t;
        task[i] = { t, s, i };
    }
    std::sort(task + 1, task + n + 1);
    rep (i, 1, m) ava.push(i);
    rep (i, 1, n) {
        while (not wrk.empty()) {
            auto u = wrk.top();
            if (u[0] <= task[i][0]) {
                ava.push(u[1]);
                wrk.pop();
            }
            else break;
        }
        if (not ava.empty()) {
            int u = ava.top(); ava.pop();
            res[u].push_back(task[i][2]);
            pll T = { task[i][0] + task[i][1], u };
            wrk.push(T);
        } else {
            auto u = wrk.top(); wrk.pop();
            res[u[1]].push_back(task[i][2]);
            u[0] += task[i][1];
            wrk.push(u);
        }
    }
    rep (i, 1, m) {
        std::cout << res[i].size() << ' ';
        std::sort(res[i].begin(), res[i].end());
        for (auto x : res[i]) std::cout << x << ' ';
        std::cout << '\n';
    }
}