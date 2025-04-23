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
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

int dfs(int c , vi &visited , int curr , V<vi> &g){
    visited[curr] = c;
    int cnt = 0;
    for(auto next : g[curr]){
        if(!visited[next]){
            cnt += 1 + dfs(c , visited , next, g );
        }
    }
    return cnt;
}

void solve() {
    int n , q;
    cin >> n >> q;
    V<vi> g( n + 7 );
    vi cnt( n + 7 , 1 );
    for(int i = 0 ; i < q ; i++){
        int a , b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        cnt[a]++;
        cnt[b]++;
    }
    int c = 1;
    vi visited(n + 7 , 0);
    vi comp(n + 7 , 0);
    vi sum(n + 7, 0);
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            comp[c] = 1 + dfs(c , visited , i , g);
            c++;
        } 
        int comp_curr = visited[i];
        sum[comp_curr] += comp[ comp_curr ] - cnt[i];
    }

    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        ans += sum[i] / 2;
    }
    cout << ans << endl;

}

 main() {

    fastIO;
    solve();
}