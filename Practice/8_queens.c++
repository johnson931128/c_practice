#include <iostream>
using namespace std;

int n, ans = 0, put[100], visited[3][100];

void search(int now)
{
    if (now == n)
        ans++; // 跑到最後一行了，代表這組解ok
    else
        for (int i = 0; i < n; i++)
        {
            if (!visited[0][i] && !visited[1][now + i] && !visited[2][now - i + n])
            // visited[0] : 檢查col有沒有撞到, visited[1] : 檢查主隊角x+y = c, visited[2] : 檢查副對角abs(x-y) = c
            {
                // 比x+y對角線(x是now,y是i)；比x-y對角線(因為會出現負值所以+n)
                put[now] = i; // 把第now行的皇后放在第i列
                visited[0][i] = visited[1][now + i] = visited[2][now - i + n] = 1;
                search(now + 1);
                visited[0][i] = visited[1][now + i] = visited[2][now - i + n] = 0; // 改回來(回朔)
            }
        }
}

int main()
{
    cin >> n;
    search(0);
    cout << ans << '\n';
}
