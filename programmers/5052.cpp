#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    string temp;
    scanf("%d", &t);
    while (t--)
    {
        vector<string> v;
        bool tog = true;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << "\n";
        // }
        for (int i = 0; i < v.size() - 1; i++)
        {
            int curLength = v[i].length();
            int nextLength = v[i + 1].length();
            if (curLength > nextLength)
                continue;
            if (v[i + 1].find(v[i]) == 0)
            {
                tog = false;
                break;
            }
        }
        if (tog)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
