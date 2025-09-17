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
constexpr int MAXN = 2e5+7;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
vi divisors[MAXN];
void solve() {
    int n;
    cin >> n;
    vi arr(n);
    vi cnt(n + 1 , 0);
    for(auto &x : arr) cin >> x;
    int ans = 0;
    vi last_max;
    vi visit(n + 1 , 0);
    for(int i = 0 ; i < n ; i++){
        vi curr_max;
        for(auto d : divisors[ arr[i] ]){
            cnt[d]++;
            if( cnt[d] != i + 1 ) ans = max(ans , cnt[d]);
            else if(!visit[d]){
                curr_max.pb(d);
                visit[d] = 1;
            } 
        }
        for(auto x : last_max){
            if(cnt[x] != i + 1){
                ans = max(ans , cnt[x]);
                visit[x] = 0;
            }else curr_max.pb(x); 
        }
        swap(last_max , curr_max);
        cout << ans << ' ';
    }
    cout << endl;
    
}

int main() {

    fastIO;

    FOR(i , 2 , MAXN) for(int j = i; j < MAXN; j+=i) divisors[j].pb(i);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}