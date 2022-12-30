#include <iostream>

using namespace std;

int binSearch(int a[], int target, int n) {
    int l = 0;
    int r = n - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (target == a[mid]) {
            return mid;
        }
        if (target > a[mid]) {
            l = mid + 1;
        }
        else if (target < a[mid]) {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target; cin >> target;
    cout << binSearch(a, target, n) << endl;
}