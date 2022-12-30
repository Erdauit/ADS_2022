#include <iostream>
using namespace std;

int snake[800][800];

int BinRow(int snake[][800], int target, int n, int m) {
    int l = 0; int r = n - 1;
    int min, max; 
    while (l < r) {
        int mid = l + (r - l)/ 2;
        if (mid % 2 == 0) {
            max = snake[mid][0];
            min = snake[mid][m - 1];
        }
        else {
            min = snake[mid][0];
            max = snake[mid][m - 1];
        }

        if (target >= min && target <= max) {
            return mid;
        }
        else if (target > max) {
            l = mid + 1;
        }
        else if (target < min) {
            r = mid - 1;
        }
        else {
            return -1;
        }
    }
    return -1;
}

int Bin(int row[], int target, int m) {
    int l = 0; int r = m - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l)/ 2;
        if (target == row[mid]) {
            return mid;
        }
        else if (target > row[mid]) {
            l = mid + 1;
        } else if (target < mid) {
            r = mid - 1;
        }
    }
    return -1;

}
int BinDecrease(int row[], int target, int m) {
    int l = 0; int r = m - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l)/ 2;
        if (target == row[mid]) {
            return mid;
        }
        else if (target > row[mid]) {
            r = mid - 1;            

        } else if (target < row[mid]) {
            l = mid + 1;
        }
    }
    return -1;

}

int main () {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int row, column;
    cin >> row >> column;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> snake[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int returnedRow = BinRow(snake, a[i], row, column);
        if (returnedRow % 2 == 0) {
            cout << returnedRow <<" "<< BinDecrease(snake[returnedRow], a[i], column) << '\n';
        } else if (returnedRow % 2 == 1) {
            cout << returnedRow <<" "<< Bin(snake[returnedRow], a[i], column) << '\n';
        } else if (returnedRow == -1) {
            cout << -1 << '\n';
        }
    }
}