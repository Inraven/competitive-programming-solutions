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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+5;
using pi = pair<int, int>;
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

struct MaxMatching {
    int N;
    vector<vector<int>> adj;
    vector<pair<int, int>> label;
    vector<int> mate, first;
    vector<bool> white;

    MaxMatching(int _N) : N(_N), adj(vector<vector<int>>(N + 1)), mate(vector<int>(N + 1)), first(vector<int>(N + 1)), label(vector<pair<int, int>>(N + 1)), white(vector<bool>(N + 1)) {}

    void addEdge(int u, int v) { adj.at(u).push_back(v), adj.at(v).push_back(u); }

    int group(int x) {
        if (white[first[x]]) first[x] = group(first[x]);
        return first[x];
    }
    void match(int p, int b) {
        swap(b, mate[p]);
        if (mate[b] != p) return;
        if (!label[p].second) mate[b] = label[p].first, match(label[p].first, b);  // label del vertice
        else match(label[p].first, label[p].second), match(label[p].second, label[p].first);  // label de la arista
    }
    bool augment(int st) {
        assert(st);
        white[st] = true;
        first[st] = 0;
        label[st] = {0, 0};

        queue<int> q;
        q.push(st);

        while (!q.empty()) {
            int a = q.front();
            q.pop();  // vertice exterior
            for (auto& b : adj[a]) {
                assert(b);
                if (white[b]) {
                    int x = group(a), y = group(b), lca = 0;
                    while (x || y) {
                        if (y) swap(x, y);
                        if (label[x] == pair<int, int>{a, b}) {
                            lca = x;
                            break;
                        }
                        label[x] = {a, b};
                        x = group(label[mate[x]].first);
                    }
                    for (int v : {group(a), group(b)}) while (v != lca) {
                        assert(!white[v]);  // haz blanco a todo a lo largo del camino
                        q.push(v);
                        white[v] = true;
                        first[v] = lca;
                        v = group(label[mate[v]].first);
                    }
                } else if (!mate[b]) {
                    mate[b] = a;
                    match(a, b);
                    white = vector<bool>(N + 1);  // reset
                    return true;
                } else if (!white[mate[b]]) {
                    white[mate[b]] = true;
                    first[mate[b]] = b;
                    label[b] = {0, 0};
                    label[mate[b]] = {a, 0};
                    q.push(mate[b]);
                }
            }
        }
        return false;
    }
    int solve() {
        int ans = 0;
        for (int st = 1; st <= N; ++st) if (!mate[st]) ans += augment(st);
        for (int st = 1; st <= N; ++st) if (!mate[st] && !white[st]) assert(!augment(st));
        return ans;
    }
};

void solve() {
    int n , m;
    cin >> n >> m;
    vi cnt(m+1,0);
    MaxMatching xd(m+n+1);
    for(int i = m+1 ; i <= m+n ; i++){
        int q;
        cin>>q;
        for(int j = 0 ; j < q ; j++){
            int x;
            cin>>x;
            xd.addEdge(i,x);
        }
    }
   cout<<m-xd.solve();

}

int main() {

    fastIO;
    solve();
}