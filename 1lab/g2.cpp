#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime (int n) {

    if(n == 0 or n == 1) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main () {
    vector <int> prime;
    for(int i = 2; i < 10000; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    vector <int> superprime;
    for (int j = 0; j < prime.size(); j++) {
        if (isPrime(j+1)) {
            superprime.push_back(prime[j]);
        }
    }

    int c;
    cin >> c;
    cout << superprime[c-1] << endl;
}