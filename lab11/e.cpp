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
#define MAXN 1000500
#define dbg(x) cout<<(#x)<<":   "<<x<<'\n';
#define fi(n)  for(ll i = 0; i < (n); i++)
#define fj(n)  for(ll j = 0; j < (n); j++)
#define fio(n) for(ll i = 1; i < (n); i++)
using namespace std;

ll n, m, a, b, c;
vector<ll> gr[MAXN];
ll par[MAXN];
ll ans[MAXN];

// Disjoint set data structure
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
    cin >> n >> m;
    fi(n) par[i] = i;
    fi(m){
        cin >> a >> b; a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    ll cur = 0;
    for(ll i = n-1; i > 0; i--){
        for(ll k : gr[i]) if (k > i) 
            cur += merge(k, i); 
        ans[i-1] = n - i -cur;
    }
    fi(n) cout << ans[i] << '\n';
    return 0;
}