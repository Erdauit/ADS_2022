#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int> a, int power) {
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l)/ 2;
        if (power >= a[mid]) {
            l = mid + 1;
        }
        else if (power <= a[mid]) {
            r = mid - 1;
        }
        else if (power == a[mid]) {
            return l;
        }
    }    
    return l; 
}


int main () {
    int n; cin >> n;
    vector <int> vec;
    int x;    
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }    
    sort(vec.begin(), vec.end());
    int round; cin >> round;
    int power[round]; 

    for (int i = 0; i < round; i++) {
        int x; cin >> x;
        int ans = BinarySearch(vec, x);
        int sum = 0;
        for (int j = 0; j < ans; j++) {
            sum += vec[j];
        }
        cout << ans << " " << sum << endl;
    }
}


