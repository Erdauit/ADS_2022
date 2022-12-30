#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

long long n, m, a, b, c, x;
pair<long long,long long> ar[1000000];
long long d[1000000];
bool was[1000000];

long long dijkstra(long long s, long long f){
    for(long long i = 0; i < n; i++){
        d[i] = (long long) INT32_MAX;
    }
    for(long long i = 0; i < n; i++){
        was[i] = false;
    }
    d[s] = 0;
    for(long long i = 0; i < n; i++){
        long long v = -1;
        for(long long j = 0; j < n; j++) {
            if (!was[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (v == -1 || d[v] == (long long) INT32_MAX) {
            break;
        }
        was[v] = true;
        for(long long j = 0; j < n; j++){
            long long to = j, len = abs(ar[j].first - ar[v].first)  + abs(ar[j].second - ar[v].second);
            d[to] = min(d[to], max(d[v], len));
        }
    }
    return d[f];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> ar[i].first >> ar[i].second;
    }
    cout << dijkstra(0, n-1);
    return 0;
}