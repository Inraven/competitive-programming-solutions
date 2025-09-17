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
void sieve(int n , vi &primes) {
  vector<bool> is_prime(n + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if(!is_prime[p])continue;
    for(ll i=p*p;i<=n;i+=p)is_prime[i]=0;
    primes.pb(p);
  }
}
void solve() {
    int n;
    cin >> n;
    vector<int>primes;
    sieve(n , primes);
    reverse(all(primes));
    
    vi ans(n + 1, 0);
    vi visit(n + 1 , 0);

    for(auto p : primes){
        vi nums;
        for(int k = p ; k <= n ; k += p) if(!visit[k]) nums.pb(k);           
        if( SZ(nums) > 1 ){
            for(int k = 0 ; k < SZ(nums) ; k++){
                int u = nums[k];
                int v = nums[ (k + 1) % SZ(nums) ];
                ans[u] = v;
                visit[u] = 1;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        cout << (ans[i] ? ans[i] : i) << ' ';
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