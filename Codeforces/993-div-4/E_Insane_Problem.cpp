//Author: AngelRuiz
#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)

#define V vector
#define pb push_back
#define pf push_front
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define all(v) v.begin(),v.end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max


void solve() {
    ll k , lx , rx , ly , ry;
    cin >> k >> lx >> rx >> ly >> ry;  
    ll exp = 1;
    V<ll> ks(1,1);
    for(int i = 0 ; i < 64 ; i++){
        exp *= k;
        if(exp > 1e9) break;
        ks.pb(exp);
    }
    ll ans = 0;

    for(auto k : ks){
        
        ll lim_l , lim_r ;
        lim_l = max( ly , k * lx );
        lim_r = min( ry , k * rx );

        lim_l--;
        if(lim_r < lim_l) continue;
       // cout << lim_l  << ' ' << lim_r << endl;
        ans += (lim_r / k) - (lim_l / k);
    }
    cout << ans << endl;
   // cout << endl << endl << endl;
}

int main() {

    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}