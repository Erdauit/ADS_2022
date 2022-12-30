#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int a) {
    if (a == 0) return false;
    if (a == 1) return false;
    for(int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            a.push_back(i);
        } 
    }

    int a1;
    int a2;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            if (a[i] + a[j] == n){
                // a1 = a[i];
                // a2 = a[j];
                cout << a[i] << " " << a[j];
                return 0;
            }
        }
    }
}