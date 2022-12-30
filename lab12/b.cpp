#include <iostream>
#include <vector>
#include <set>


using namespace std;

long long n, m, a, b, c;
vector<pair<long long,long long>> gr[1000000];
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
    set<pair<long long,long long>> q;
    q.insert({d[s], s});
    for(long long i = 0; i < n; i++){
        if (q.empty()) {
            break;
        }
        long long v = q.begin()->second;
        q.erase(q.begin());
        was[v] = true;
        for(pair<long long,long long> j : gr[v]){
            long long to = j.first, len = j.second;
            if (was[to]) continue;

            if (d[v] + len < d[to]){
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    return d[f];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(long long i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        gr[a].push_back(make_pair(b, c));
        gr[b].push_back(make_pair(a, c));
    }
    long long d;
    cin >> a >> b >> c >> d; a--;
    b--;
    c--;
    d--;
    long long ans = min(dijkstra(a, b) + dijkstra(b, c) + dijkstra(c, d),
                dijkstra(a, c) + dijkstra(c, b) + dijkstra(b, d));
    if (ans >= (long long) INT32_MAX) cout << -1;
    else cout << ans;
    return 0;
}