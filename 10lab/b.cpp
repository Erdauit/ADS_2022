#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, s, e;
    int cnt = 0;
    cin >> n;
    int erdauit[n][n];
    vector<bool> used(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> erdauit[i][j];
        }
    }
    cin >> s >> e;
    s--;
    e--;

    if (s == e)
    {
        cout << cnt << endl;
        return 0;
    }
    queue<int> q;
    q.push(s);
    used[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        cnt++;

        for (int i = 0; i < n; i++)
        {
            if (!used[i] && erdauit[u][i])
            {
                if (i == e)
                {
                    cout << cnt << endl;
                    return 0;
                }
                used[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    cout << -1 << endl;

    return 0;
}