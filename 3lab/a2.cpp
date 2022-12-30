#include <iostream>

using namespace std;

int snake[800][800];

// int Bin(int row[], int target, int m) {
//     int l = 0; int r = m - 1;
//     int mid;
//     while (l <= r) {
//         mid = l + (r - l)/ 2;
//         if (target == row[mid]) {
//             return mid;
//         }
//         else if (target > row[mid]) {
//             l = mid + 1;
//         } else if (target < mid) {
//             r = mid - 1;
//         }
//     }
//     return -1;

// }
// int BinDecrease(int row[], int target, int m) {
//     int l = 0; int r = m - 1;
//     int mid;
//     while (l <= r) {
//         mid = l + (r - l)/ 2;
//         if (target == row[mid]) {
//             return mid;
//         }
//         else if (target > row[mid]) {
//             r = mid - 1;            

//         } else if (target < row[mid]) {
//             l = mid + 1;
//         }
//     }
//     return -1;

// }

void BinarySearch(int target, int n, int m) {
    for (int i = 0; i < n; i++) {
        int l = 0; int r = m - 1;
        int mid;
        if (i % 2 == 0) {
            while (l <= r) {
                mid = l + (r - l)/ 2;
                if (target == snake[i][mid]) {
                    cout << i << " " << mid << endl;
                    return;
                }
                else if (target > snake[i][mid]) {
                    r = mid - 1;            

                } else if (target < snake[i][mid]) {
                    l = mid + 1;
                }
            }
        }
        else {
            while (l <= r) {
                mid = l + (r - l)/ 2;
                if (target == snake[i][mid]) {
                    cout << i << " " << mid << endl;
                    return;
                }
                else if (target > snake[i][mid]) {
                    l = mid + 1;    

                } else if (target < snake[i][mid]) {
                    r = mid - 1;        
                }
            }
        }
    }
    cout << -1 << endl;
}



int main () {

    int n, m, size;

    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    cin >> n >> m;    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> snake[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        int target = a[i];
        BinarySearch(target, n, m);
    }



}