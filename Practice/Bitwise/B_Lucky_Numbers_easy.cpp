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
    V<ll> numbers;
    for(ll i = 1 ; i < (1 << 10) ; i++){
        int cnt = __builtin_popcount(i);
        int sz = __lg(i) + 1 ;
        if( sz&1 || (sz - cnt) != (sz / 2) ) continue;
      
        ll x = i;
        ll n1 = 0;
        ll n2 = 0;
        while(x > 0){
            n1 *= 10;
            n2 *= 10;
            n1 += (x&1?4:7);
            n2 += (x&1?7:4);
            x >>= 1;
        }
        numbers.pb(n1);
        numbers.pb(n2);
    }
    sort(all(numbers));
    int x;
    cin >> x;
    cout << *lower_bound(all(numbers), x) << endl;
}

int main() {

    fastIO;
    solve();
}