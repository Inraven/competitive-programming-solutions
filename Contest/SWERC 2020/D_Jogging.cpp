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


vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph) {
    const int INF = INT_MAX;
    int n = graph.size();
    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u])
            continue;

        for (auto &[v, dv] : graph[u]) {
            if (du + dv < dist[v]) {
                dist[v] = du + dv;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

void solve() {
    int n , m , minDist, maxDist;
    cin >> n >> m >> minDist >> maxDist;
    V< V < pi > > g(n);
    V< pi > input;
    //V<pi> cam;
    for(int i = 0 ; i < m ; i++){
        int u , v , c;
        cin >> u >> v >> c;
        g[u].emplace_back(v , c);
        g[v].emplace_back(u , c);
        input.emplace_back( u , v );
    }

    vi cost = dijkstra(0 , g);
    int ans = 0;
    for(auto &[u , v] : input){
        int dist = min( cost[u] , cost[v] ) * 2;
        //cout << u << ' ' << v << ' ' << dist << endl;
        if( dist < maxDist ) ans++;
    }
    cout << ans << endl;

}

int main() {

    fastIO;
    solve();
}