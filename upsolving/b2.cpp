#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes(int n)
{
    bool prime[n];

    vector<int> p;
    prime[0] = prime[1] = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == false)
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = true;
            }
    }

    for (int i = 0; i < n; i++)
    {
        if (prime[i] == false)
            p.push_back(i);
    }
    return p;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p = primes(n);
    int a, b;
    // for (int i = 0; i < p.size(); i++)
    //     cout << p[i] << " ";

    for (int i = 0; i < p.size(); i++) {
        int l = 0, r = p.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(p[i] + p[mid] == n) {

                cout << p[i] << " " << p[mid];
                return 0;
            }
            else if (p[i] + p[mid] > n) {
                r = mid - 1;
            }
            else if (p[i] + p[mid] < n) {
                l = mid + 1;
            }
        }
    }
    return 0;
}