#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

long long n, m, a, b, c, x;
vector<pair<long long, pair<long long,long long>>> edges;
pair<long long,long long> ar[1000000];
long long d[1000000];
long long p[1000000];
bool was[1000000];

void ford_bellman(){
    for(long long i = 0; i < n; i++){
        d[i] = (long long) INT32_MAX;
    }
    for(long long i = 0; i < n; i++){
        p[i] = -1;
    }
    long long x;
    for(long long i = 0; i < n; i++){
        x = -1;
        for(pair<long long, pair<long long, long long>> j : edges){
            long long c = j.first;
            long long a = j.second.first;
            long long b = j.second.second;
            if (d[b] > d[a] + c){
                d[b] = max((long long)-(long long) INT32_MAX, d[a] + c);
                p[b] = a;
                x = b;
            }
        }
    }
    if (x == -1) {
        cout << "NO";
        return;
    }
    vector<long long> pat;
    long long y = x;
    for(long long i = 0; i < n; i++) {
        y = p[y];
    }
    for(long long cur = y; ; cur = p[cur]){
        pat.push_back(cur+1);
        if (cur == y && pat.size() > 1) {
            break;
        }
    }
    cout << "YES\n";
    reverse(pat.begin(), pat.end());
    cout << pat.size() << '\n';
    for(long long i : pat){
        cout << i << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < n; j++) {
            cin >> x;
            if (x != 100000) edges.push_back(make_pair(x, make_pair(i, j)));
        }
    }
    ford_bellman();
    return 0;
}