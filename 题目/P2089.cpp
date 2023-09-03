/*
 * @Author: YttriumWillow fengziyi62625@163.com
 * @Date: 2022-07-28 14:13:02
 * @LastEditors: YttriumWillow fengziyi62625@163.com
 * @LastEditTime: 2022-09-11 13:23:22
 * @FilePath: \problems\P_2089_烤鸡.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
#define longint long long
#define reg register
#define _read =read()
using namespace std;
int n, ansc;
vector<vector<int>> ans;
vector<int> tmp;
int main()
{
    cin >> n;
    for (int a = 1; a <= 3; a++)
        for (int b = 1; b <= 3; b++)
            for (int c = 1; c <= 3; c++)
                for (int d = 1; d <= 3; d++)
                    for (int e = 1; e <= 3; e++)
                        for (int f = 1; f <= 3; f++)
                            for (int g = 1; g <= 3; g++)
                                for (int h = 1; h <= 3; h++)
                                    for (int i = 1; i <= 3; i++)
                                        for (int j = 1; j <= 3; j++)
                                            if (a + b + c + d + e + f + g + h + i + j == n)
                                            {
                                                tmp = {a, b, c, d, e, f, g, h, i, j};
                                                // printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
                                                ans.push_back(tmp);
                                                ansc++;
                                            }
    cout << ansc << endl;
    int x = ans.size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}