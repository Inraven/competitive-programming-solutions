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

vector<int> fact[MAXN];
int arr[MAXN];
vector<int>pos[MAXN];


void solve() {
    int n , q;
    cin >> n >> q;
    for(int i = 0;i <= 1e5;i++) pos[i].clear();
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        int x = arr[i];
        pos[x].pb(i);
    }

    while(q--){
        ll k , l , r;
        cin >> k >> l >> r;
        r--;
        l--;
        ll ans = 0;
        int i = l;
        while(i <= r){
            int idx = r;
            for(auto x : fact[k]){
                int p = lower_bound(all(pos[x]),i) - pos[x].begin();
                if(p < SZ(pos[x]))  
                    idx = min( pos[x][p] , idx);
            }
            ans += k * abs(i - idx);
            while( k % arr[idx] == 0 ) k /= arr[idx]; 
            i = idx;
            if(i == r) break;
        }
        ans += k;
        cout << ans << endl;   
    }
}

int main() {

    fastIO;
    int t;
    cin >> t;
    for(int i = 2;i <= (int)1e5;i++){
        for(int j = i;j <= (int)1e5;j+=i){
            fact[j].push_back(i);
        }
    }
    while(t--) {
        solve();
    }

    return 0;
}