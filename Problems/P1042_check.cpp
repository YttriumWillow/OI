#include<bits/stdc++.h>
using namespace std;
string s;
int w11, w21, l11, l21;
int w[10000005];
int l[10000005];
bool fl;
int tr, tl;
int main()
{
    while (1)
    {
        getline(cin, s);
        int lens = s.size();
        for (int i = 0; i < lens; i++)
        {
            if (s[i] == 'W')
                w11++, w21++;
            else if (s[i] == 'L')
                l11++, l21++;
            else if (s[i] == 'E')
            {
                fl = 1;
                break;
            }
            if (w11 == 11 || l11 == 11)
            {
                cout << w11 << ':' << l11 << endl;
                w11 = 0, l11 = 0;
            }
            else if (w21 == 21 || l21 == 21)
            {
                w[++tr] = w21;
                l[++tl] = l21;
                w21 = 0, l21 = 0;
            }
        }
        if (fl)
        {
            cout << w11 << ':' << l11 << endl << endl;
            w[++tr] = w21;
            l[++tl] = l21;
            break;
        }
    }
    for (int i = 1;i <= tr;i++)
        cout << w[i] << ':' << l[i] << endl;
    return 0;
}