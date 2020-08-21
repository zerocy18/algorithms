#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> v;

void solution(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s.substr(i));
    }
    sort(v.begin(), v.end());
}

int main()
{
    string q;
    cin >> q;
    solution(q);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}
