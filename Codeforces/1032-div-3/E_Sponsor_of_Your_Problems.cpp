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

int dp(int pos , bool l , bool r , V<V<vi>> &memo , string &strL, string &strR){
    if(pos == SZ(strL)) return 0;
    if(memo[pos][l][r] != -1) return memo[pos][l][r];
    int cost = INT_MAX;
    int ini = l ? strL[pos] - '0' : 0;
    int fin = r ? strR[pos] - '0' : 9;
    for(int d = ini ; d <= fin ; d++){
        int curr = (d == (strL[pos] - '0')) + (d == (strR[pos]-'0'));
        bool nl = l && (d == ini);
        bool nr = r && (d == fin);
        int t = curr + dp(pos + 1, nl , nr , memo , strL, strR);
        cost = min(cost , t);
    }
    memo[pos][l][r] = cost;
    return cost;
}

void solve() {
    ll l , r;
    cin >> l >> r;
    string strL = to_string(l);
    string strR = to_string(r);
    V<V<vi>> memo(11 , V<vi>(2 , vi(2, -1)));
    int ans = dp(0, 1, 1,memo,strL,strR);
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