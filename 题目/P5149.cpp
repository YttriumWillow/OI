#include <bits/stdc++.h>
#define longint long long
#define reg register int
#define _read =read()
#define qwq puts("fzy qwq!");
using namespace std;
map<string, longint> seat;
longint n, len, ans; string str;
longint a[100010], b[100010];
void merge_sort(int left, int right)
{
    if (left >= right) return;
    int mid = (right - left) / 2 + left;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], ans += mid - i + 1;
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= right) b[k++] = a[j++];
    for (int i = left;i <= right;i++) a[i] = b[i];
}
int main()
{
    cin >> n;
    for (reg i = 1; i <= n; i++)
    {
        cin >> str;
        seat[str] = i;
    }
    for (reg i = 1; i <= n; i++)
    {
        cin >> str;
        a[++len] = seat[str];
    }
    // for (reg i = 1; i <= n; i++)
    //     cout << sha[i] << endl;
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}