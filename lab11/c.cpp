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
ll ar[1100];
ll par[600];

ll find(ll x){
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

bool merge(ll a, ll b){
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rand()&1) swap(a, b);
    par[a] = b;
    return true;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n >> m >> x >> y;
    fi(n) par[i] = i;
    vector<pair<ll, pll>> edges;
    string s;
    fi(m){
        cin >> s >> a >> b >> c; a--, b--;
        if (s == "both")   c = c*min(x, y);
        else if (s == "big")   c = c*x;
        else if (s == "small") c = c*y;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for(auto i : edges){
        if (merge(i.s.f,i.s.s)) ans += i.f;
    }
    cout << ans;


    return 0;
}