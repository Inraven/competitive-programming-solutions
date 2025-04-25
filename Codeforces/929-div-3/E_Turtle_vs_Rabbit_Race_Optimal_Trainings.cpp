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

ll sumatoria(ll x){
    return ( (x * ( x + 1 ) ) / 2);
}

ll f(int r, ll s1 , ll u , V<ll>&prefix){
    ll cnt = prefix[r] - s1;
    cnt--;
    ll v = u - cnt;
    if(v>0) v--;
    return sumatoria(u) - sumatoria( abs(v) );
}

ll ternary_search(ll l, ll r , ll u, ll s1 , V<ll>&prefix) {
    while (r - l > 2) {
      ll m1 = l + (r - l) / 3;
      ll m2 = r - (r - l) / 3;
      ll f1 = f(m1,s1,u,prefix);
      ll f2 = f(m2,s1,u,prefix);
      if (f1 < f2)
        l = m1;
      else
        r = m2;
    }
    ll aux = 0;
    ll ans = l;
    for(int i = l ; i <= r ; i++){
        ll x = f(i,s1,u,prefix);
        if(x > aux){
            aux = x;
            ans = i;
        }
    }
    return ans;
  }

void solve() {
    int n;
    cin >> n;
    V<ll>prefix(1 , 0);
    for(int i = 0 ; i < n ; i++){
        ll x;
        cin >> x;        
        prefix.pb(x + prefix.back());
    }
    int q;
    cin >> q;

    while(q--){
        ll l , u;
        cin >> l >> u;
        cout << ternary_search(l , n , u , prefix[l-1], prefix) << ' ';
    }
    cout << endl;
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