#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int primes (int n) {
    int c = 2;
    int cnt = 0;
    bool found = false;
    while (n > 1) {
        if (n % c == 0) {
            if (found == false) {
                cnt++;
            }
            found = true;
            n /= c;
        }
        else {
            c++;
            found = false;
        }
    }
    return cnt;
}

int primes2 (int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << primes2(n)<< endl;
}