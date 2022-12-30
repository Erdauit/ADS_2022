#include <bits/stdc++.h>
using namespace std;

int rows, cols, cnt;

void dfs(char **erda, int i, int j)
{
    if (i >= rows or j >= cols or i < 0 or j < 0 or erda[i][j] == '0')
        return;
    erda[i][j] = '0';
    dfs(erda, i + 1, j);
    dfs(erda, i - 1, j);
    dfs(erda, i, j + 1);
    dfs(erda, i, j - 1);
}

int main()
{
    cin >> rows >> cols;
    char **matrix = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
            {
                dfs(matrix, i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}