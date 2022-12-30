#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

long long n, m, a, b, c, x;
vector<long long> gr[1000000];
set<pair<long long,long long>> S;
long long d[1000000];

long long bfs(long long s, long long f){
    for(long long i = 0; i < n; i++){
        d[i] = (long long) INT32_MAX;
    }
    queue<long long> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        long long cur = q.front(); q.pop();
        for(long long j : gr[cur]){
            if (d[j] == (long long) INT32_MAX){
                d[j] = d[cur]+1;
                q.push(j);
            }
        }
    }
    if (d[f] == (long long) INT32_MAX) return -1;
    return d[f];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(long long i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        S.insert(make_pair(a, b));
        S.insert(make_pair(b, a));
    }
    bool piw = S.find(make_pair(0, n-1)) == S.end();
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){

            if (i != j){
                if (S.find({i, j}) == S.end()){
                    if (!piw) {
                        gr[i].push_back(j);
                    }
                }else if (piw){
                    gr[i].push_back(j);
                }
            }
        }
    }
    cout << bfs(0, n-1);
    return 0;
}