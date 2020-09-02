#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> m1;
map<string, int> m2;
void parsing1(string s1)
{
    string temp = "";
    for (int i = 0; i < s1.size() - 1; i++)
    {
        if ('A' <= s1[i] && s1[i] <= 'Z')
        {
            if ('A' <= s1[i + 1] && s1[i + 1] <= 'Z')
            {
                temp.push_back(s1[i]);
                temp.push_back(s1[i + 1]);
            }
        }
        if (temp.empty())
            continue;
        m1[temp]++;
        temp = "";
    }
}
void parsing2(string s2)
{
    string temp = "";
    for (int i = 0; i < s2.size() - 1; i++)
    {
        if ('A' <= s2[i] && s2[i] <= 'Z')
        {
            if ('A' <= s2[i + 1] && s2[i + 1] <= 'Z')
            {
                temp.push_back(s2[i]);
                temp.push_back(s2[i + 1]);
            }
        }
        if (temp.empty())
            continue;
        m2[temp]++;
        temp = "";
    }
}

int calcInter(map<string, int> m1, map<string, int> m2)
{
    int sum = 0;
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        if (m2[it->first] > 0)
        {
            sum += min(it->second, m2[it->first]);
        }
    }
    return sum;
}

int calcUnion(map<string, int> m1, map<string, int> m2)
{
    int sum = 0;
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        if (m2[it->first] == 0)
        {
            sum += it->second;
        }
        if (m2[it->first] > 0)
        {
            sum += max(it->second, m2[it->first]);
        }
    }
    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        if (m1[it->first] == 0)
        {
            sum += it->second;
        }
    }

    return sum;
}

int solution(string str1, string str2)
{
    int answer = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        str1[i] = toupper(str1[i]);
    }
    for (int i = 0; i < str2.size(); i++)
    {
        str2[i] = toupper(str2[i]);
    }
    parsing1(str1);
    parsing2(str2);

    int inter = calcInter(m1, m2);
    int uni = calcUnion(m1, m2);
    if (inter == 0 && uni == 0)
    {
        answer = 65536;
    }
    else
    {
        answer = inter * 65536 / uni;
    }
    return answer;
}
