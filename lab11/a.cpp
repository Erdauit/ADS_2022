#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <ctime>
#include <list>

#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
#define dbg(x) cout<<(#x)<<":   "<<x<<'\n';
#define fi(n)  for(ll i = 0; i < (n); i++)
#define fj(n)  for(ll j = 0; j < (n); j++)
#define fio(n) for(ll i = 1; i < (n); i++)
using namespace std;

ll n, m, a, b, c, x, y;
ll ar[200500];
ll par[200500];
ll le[200500];
ll ri[200500];

ll find(ll x){
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(ll a, ll b){
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rand()&1) swap(a, b);
    par[a] = b;
    le[b] = min(le[a], le[b]);
    ri[b] = max(ri[a], ri[b]);
    return true;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n >> m;
    fi(n) par[i] = i, le[i] = i, ri[i] = i;
    vector<pair<ll, pll>> edges;
    string s;
    fi(m){
        cin >> a >> b >> c; a--, b--;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    ll ans = 0, mm = -1, cnt = 0;
    for(auto i : edges){
        if (cnt >= n-1) break;
        ll l = i.s.f, r = i.s.s, c = i.f;
        mm = l;
        for(ll i = l; i <= r; i++) {
            if (find(i) != i) {
                mm = find(i);
                break;
            }
        }
        if (le[mm] <= l && r <= ri[mm]) continue;
        else if (le[mm] <= r && r <= ri[mm]) r = le[mm];
        else if (le[mm] <= l && l <= ri[mm]) l = ri[mm];
        for(ll i = l; i <= r; i++){
            if (merge(mm, i)) {
                ans += c, cnt++;
            }
        }
    }
    cout << ans;


    return 0;
}