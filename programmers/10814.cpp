#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
int n;
typedef struct member
{
    int age;
    string name;
    int order;
} member;

bool cmp(member q, member p)
{
    if (q.age == p.age)
    {
        return q.order < p.order;
    }
    else
    {
        return q.age < p.age;
    }
}

int main()
{

    cin >> n;
    vector<member> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].age >> v[i].name;
        v[i].order = i;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].age << " " << v[i].name << "\n";
    }

    return 0;
}
