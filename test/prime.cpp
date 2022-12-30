#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int target) {
    if (target == 0) return false;
    if (target == 1) return false;
    for (int i = 0; i < sqrt(target); i++) {
        if (target % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    int n;
    cin >> n;
    cout << isPrime(n);
}