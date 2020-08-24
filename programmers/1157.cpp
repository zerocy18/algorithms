#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int mxv = -1;
    int idx;
    vector<int> v(26);
    vector<int> c(26);
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
        v[str[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
        c[i] = v[i];
    sort(v.begin(), v.end());
    if (v[25] == v[24])
    {
        printf("?");
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (mxv < c[i])
            {
                mxv = c[i];
                idx = i;
            }
        }
        printf("%c", idx + 'A');
    }

    return 0;
}
