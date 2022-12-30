#include <iostream>
#include <cmath>
using namespace std;

bool f(int x) {
    bool res = true;
    if (x == 1)  return res = false;

    for (int i = 2; i <= sqrt(x); ++i) {
        // cout << i << " ";
        if (x % i == 0) {
            res = false;
            break;
        }

    }
        return res;
}
int main() {
    int a;
    cin >> a;
    if (f(a) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
