#include <stdio.h>
#include <string>

using namespace std;

bool checkHell(int n)
{
    string str = to_string(n);
    if (str.find("666") != string::npos)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    int cnt = 0;
    for (i = 666;; i++)
    {
        if (checkHell(i))
        {
            cnt++;
        }
        if (cnt == N)
            break;
    }
    printf("%d", i);
    return 0;
}
