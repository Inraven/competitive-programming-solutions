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
    ll n , m;
    cin >> n >> m;
    V<ll> A(n + 1 , 0) , B(m , 0);
    A[0] = LONG_LONG_MIN;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    for(auto &x : B) cin >> x;
    sort(all(B));
    for(int i = 1 ; i <= n ; i++){
        auto it = lower_bound(all(B), A[i-1] + A[i]);
        if(it == B.end()) continue;
        ll x = *it;
        
        if( max( A[i] , x - A[i] ) < A[i - 1] ){
            cout << "NO" << endl;
            return;
        }
        
        if( min(A[i] , x - A[i]) < A[i - 1] ) A[i] = max(A[i] , x - A[i]);
        else A[i] = min(A[i] , x - A[i]);
    }

    cout << (is_sorted( all(A)) ? "YES" : "NO" ) << endl;


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