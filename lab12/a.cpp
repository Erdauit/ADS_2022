#include <iostream>
#include <vector>
#include <set>

using namespace std;
long long n, m, a, b, c; long long d[500][500]; long long pos[500];
bool was[500];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }
    for (long long i = 0; i < n; i++){
        cin >> pos[i];
        pos[i]--;
    }
    for (long long k = 0; k < n; k++){
        for (long long i = 0; i < n; i++){
            for (long long j = 0; j < n; j++){
                if (d[pos[i]][pos[j]] > d[pos[i]][pos[k]] + d[pos[k]][pos[j]])
                    d[pos[i]][pos[j]] = d[pos[i]][pos[k]] + d[pos[k]][pos[j]];
            }
        }
     long long ans = 0;
        for (long long i = 0; i <= k; i++) {
            for (long long j = 0; j <= k; j++){
                ans = max(ans, d[pos[i]][pos[j]]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}