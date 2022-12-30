#include <iostream>

using namespace std;

int main()
{

    long long n, q;
    cin >> n >> q;
    long long erdauit[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> erdauit[i][j];
        }
    }

    while (q--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;

        if (erdauit[a][b] && erdauit[a][c] && erdauit[b][c])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}