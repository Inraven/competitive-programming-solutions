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
    ll n;
    cin >> n;
    V<ll> facts(1, 1);
    for(int i = 2 ; i <= 14 ; i++){
        facts.pb(i * facts.back());
    }
    int ans = 1e9;
    for(int i = 0 ; i < (1 << 14) ; i++){
        ll sum = 0;
        for(int k = 0 ; k < 14 ; k++){
            if(i & (1 << k)) sum += facts[k];
        }
        if(sum > n) continue;
        ans = min(ans , __builtin_popcountll( n - sum ) + __builtin_popcount(i) );
    }
    cout << ans << endl;
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