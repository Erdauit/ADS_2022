#include <iostream>
#include <cmath>
using namespace std;


string get_string(long long a[], long long n) {
    int mod = 1e15 + 9;
    string s = "";
    long long pow_p = 1;
    for(int i = n; i != 0; i--) {
        long long x = ((a[i] / pow_p) % mod);
        if (i > 0) {
            x = ((a[i] - a[i - 1]) / pow_p) % mod;
        }
        s += x;
        pow_p = pow_p * 2 % mod;
    }
    return s;
}



int main () {
    long long n;
    cin >> n;
    long long a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << get_string(a, n) << endl;
}