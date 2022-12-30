#include <iostream>
#include <algorithm>

using namespace std;

int binSearch(int a[], int target, int n, int first) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(first + a[mid] == target) {
            return mid;
        }
        else if (first + a[mid] > target) {
            r = mid - 1;
        }
        else if (first + a[mid] < target) {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int target; cin >> target;    
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int index = binSearch(a, target, n, a[i]);
        if(binSearch(a, target, n, a[i]) != -1){
            cout << a[i] << " " << a[index];
            return 0;
        }
    }
}