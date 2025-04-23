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
#define sz(x) (int)x.size()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 5e3+7;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max


long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll fact[MAXN] , inv[MAXN];

ll inv_mod(ll a , ll m){
    return binpow(a, m - 2);
}

void precalc(){
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = inv_mod(fact[i], MOD);
    }
}

ll nCk(ll n, ll k) {
    ll num = fact[n];
    ll den = (inv[k] * inv[n - k]) % MOD;
    return (num * den) % MOD;
}

void solve() {
    precalc();
    int n , m , k;
    cin >> n >> m >> k;

    ll ans = binpow(k, n);

    for (int i = 1; i <= k; i++) {
        ll aux = (nCk(k, i) * binpow(k - i, n)) % MOD;
        if (!(i & 1)) ans = (ans + aux) % MOD;
        else ans = (ans - aux + MOD) % MOD;
    }
    ans = (ans * nCk(m , k)) % MOD;
    cout<<ans<<endl;

}

int main() {

    fastIO;
    solve();
    return 0;
}