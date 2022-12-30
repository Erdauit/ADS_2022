#include <iostream>

using namespace std;

bool check(int x, int a[][4], int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (x >= a[i][2] && x >= a[i][3])
            cnt++;
    return cnt < k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n][4], left = 0, right = 1e9;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
    
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, a, n, k))
            left = mid;
        else 
            right = mid;
    }
    cout << left + 1 << endl;
      
    return 0;
}