#include <bits/stdc++.h>
using namespace std;
void heap_sort(int arr[], int len) {
    priority_queue< int, vector<int>, greater<int> > h;
    // priority_queue(优先队列) 是用堆实现的，该实例中用 vector 存储，以从小到大方式排列
    // 需要注意该实例用了额外 O(n) 的空间存储一个新的堆，在实际运用中可以考虑把读入数据直接推入优先队列
    for (int i = 1; i <= len; i++)
        h.push(arr[i]); // 将元素插入堆
    for (int i = 1; i <= len; i++) {
        arr[i] = h.top(); // 读取堆顶元素，重新加入原数组
        h.pop(); // 删除堆顶元素
    }
}
int main()
{
    int n;
    int a[114514];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    heap_sort(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}