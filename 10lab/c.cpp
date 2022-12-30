#include <bits/stdc++.h>

#define l long long

using namespace std;

l n, m, a, b, c;
l aws[11000];

l bfs(l a)
{
    queue<l> q;
    q.push(a);
    while (!aws[b])
    {
        l c = q.front();
        q.pop();
        if (c >= 2 && aws[c - 1] == 0)
        {
            aws[c - 1] = c;
            q.push(c - 1);
        }
        if (c * 2 <= 10000 && aws[c * 2] == 0)
        {
            aws[c * 2] = c;
            q.push(c * 2);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    bfs(a);
    vector<l> ans;
    while (b != a)
    {
        ans.push_back(b);
        b = aws[b];
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (l i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}