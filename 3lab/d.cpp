#include <iostream>
#include <algorithm>

using namespace std;

int BinSearc(int a[], int target, int n, bool left) {
    int l = 0; int r = n - 1;
    int mid; 
    while (l <= r) {
        mid = l + (r - l)/ 2;
        if (target == a[mid]) {
            return mid;
        }
        else if (target > a[mid]) {
            l = mid + 1;
        } else if (target < a[mid]) {
            r = mid - 1;
        }
    }
    if (left) return l;
    return r;
}

bool Proverka(int l1, int r1, int l2, int r2) {
    int l = max (l1, l2);
    int r = min (r1, r2);
    if (l <= r) {
        return false;
    }
    return true;
}
 
int main () {
    int n; cin  >> n;
    int q, col = 4; cin >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int arr[q][col];
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
    int cnt = 0;   
        for (int j = 0; j < col; j++) {
            int l1 = arr[i][0];
            int r1 = arr[i][1];
            int l2 = arr[i][2];
            int r2 = arr[i][3];
            if (Proverka(l1, r1, l2, r2) == false) {
                int l = min (l1, l2);
                int r = max (r1, r2); 
                cnt = BinSearc(a, r, n, false) - BinSearc(a, l, n, true) + 1;
            }
            else {         
                cnt = BinSearc(a, r1, n, false) - BinSearc(a, l1, n, true) + 1;
                cnt += BinSearc(a, r2, n, false) - BinSearc(a, l2, n, true) + 1;
                }
            }
        cout << cnt << endl;
        }

    }
