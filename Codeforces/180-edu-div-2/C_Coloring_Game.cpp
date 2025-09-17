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
    int n;
    cin >> n;
    V<ll> A(n , 0);
    for(auto &x : A){
        cin >> x;
    }
    sort(all(A));
    
    ll ans = 0;
    for(int i = 2 ; i < n ; i++){
        ll aux = (i == n - 1 ?  A[n - 2] : A[n - 1]);
        ll mx = max(A[i], aux - A[i]);
        
        ll l = 0;
        ll r = i - 1;
        while(l < r){
            ll sum = A[l] + A[r];
            if(sum > mx){
                ans += (r - l);
                r--;
            }else l++;
        }
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