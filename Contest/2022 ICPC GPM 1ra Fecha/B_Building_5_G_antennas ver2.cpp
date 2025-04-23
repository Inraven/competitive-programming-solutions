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
constexpr int MAXN = 1e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
V<vi>g;
int k;
pqg XD;
V<bool>lis;
V<bool>ant;
V<int>distancia;
void dfs( int node , int dist , V<bool> &visit ){
    if(dist >= k) return;
    visit[node] = 1;
    for(auto next : g[node]){
        if(!lis[next]){
            XD.push(next);
            lis[next] = 1;
        } 
        if(!visit[next] && !ant[next] && dist + 1 < distancia[next]){
            distancia[next] = dist + 1;
            dfs(next, dist + 1, visit);
        }
    }

}

void solve() {
    int n;
    cin >> n >> k;
    g = V<vi>(n + 1);
    lis = V<bool>(n + 1, false);
    ant = V<bool>(n + 1, false);
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b;
        cin >> a >> b;
        g[b].pb(a);
        g[a].pb(b);
    }
    vi ans;

    XD.push(1);
    lis[1] = 1;
    distancia = vi(n+1,INT_MAX);
    while(!XD.empty()){
        int node = XD.top();
        XD.pop();
        ant[node] = 1;
        ans.pb(node);
        V<bool>visit(n + 1, false);
        dfs(node , 0 , visit);
    }
    for(auto x : ans) cout<<x<<' ';
}

int main() {

    fastIO;
    solve();
}