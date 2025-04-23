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
constexpr int MAXN = 2e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

class SegmentTree {
private:
    vector<int> segtree;
    vector<int> a;
    vector<int> b;
    int n , l , r;

    void build(int node, int b1, int e){
        if (b1 == e) segtree[node] = b[b1];

        else{
            int mid = (b1 + e) / 2;

            build(2 * node, b1, mid);
            build(2 * node + 1, mid + 1, e);

            l = segtree[2 * node];
            r = segtree[2 * node + 1];

            if (a[l] < a[r]) segtree[node] = l;

            else if (a[l] > a[r]) segtree[node] = r;

            else if (a[l] == a[r]) segtree[node] = l;
        }
    }

    int query(int node, int b1, int e, int L, int R){

        if (b1 > R || e < L) return -1;

        if (b1 >= L && e <= R) return segtree[node];

        int mid = (b1 + e) / 2;

        int left = query(2 * node, b1, mid, L, R);
        int right = query(2 * node + 1, mid + 1, e, L, R);
        if (left == -1) return right;

        else if (right == -1) return left;

        else{
            if (a[left] > a[right]) return right;

            else return left;
        }
    }

    void update(int node, int b1, int e, int ind, int value){

        if (b1 == e){
            segtree[node] = ind;
            a[ind] = value;
        }
        else{
            int mid = (b1 + e) / 2;

            if (ind <= mid) update(2 * node, b1, mid, ind, value);

            else update(2 * node + 1, mid + 1, e, ind, value);

            int l = segtree[2 * node];
            int r = segtree[2 * node + 1];

            if (a[l] > a[r]) segtree[node] = r;

            else segtree[node] = l;
        }
    }

public:

    SegmentTree(vi A){
        n = A.size();
        segtree = vi( (n+1)*4 , 0);
        a = vi(n+1 , 0);
        b = vi(n+1 , 0);
        for(int i = 1 ; i <= n ; i++){
            a[i] = A[i-1];
            b[i] = i;
        }
        l = 0;
        r = 0;
        build(1, 1, n);
    }

    pair<int,int> query(int L ,int R){
        int idx = query(1, 1 , n , L + 1  , R + 1 ) - 1;
        return { idx, a[idx+1] };
    }
    void update(int idx , int v){
        update(1 , 1 , n , idx + 1 , v);
    }
};


int k;
vi g[MAXN];
int in[MAXN], out[MAXN], toursz = 0;
vi padre(MAXN,0);


void eulerTour(int u, int p) {
  in[u] = toursz++;

  for (auto& v : g[u])
    if (v != p){
        padre[v] = u;
        eulerTour(v, u);
    }
      

  out[u] = toursz++;
}


void solve() {
    int n;
    cin >> n >> k;

    for(int i = 0 ; i < n - 1 ; i++){
        int a , b;
        cin >> a >> b;
        g[b].pb(a);
        g[a].pb(b);
    }
    eulerTour(1 ,0);
    vi val( n*2 , 0);
    vi dist(n*2 , 0);
    for(int i = 1 ; i <= n ; i++){
        val[ in[i] ]  =  1;
        val[ out[i] ] = -1;
    }

    partial_sum(all(val) , dist.begin());

    for(int i = 1 ; i <= n ; i++){
        dist[out[i]] = dist[in[i]];
    }


    vi pos(n*2 , 0);

    for(int i = 1 ; i <= n ; i++){
        pos[in[i]] = i;
    }

    SegmentTree st(dist);

    set<int>lis;

    lis.insert(1);


    vi ans;
    while(!lis.empty()){

        int x = *lis.begin();
        lis.erase(lis.begin());

        ans.pb(x);

        int aux = 0;
        int K = k;
        do{
            if(K == 0) break;
            if(x == 0) break;
            auto q = st.query( in[x], out[x] );
            int i = q.f;
            int v = q.s;

            if(v == INT_MAX){
                x = padre[x];
                K--;
                continue;
            }
            
            aux = (dist[i] - dist[in[x]]);

            if( aux <= K){

                st.update( i , INT_MAX);
                st.update( out[pos[i]] , INT_MAX );

                if(pos[i] != x) lis.insert(pos[i]);
            }
            if( aux > K ){
                x = padre[x];
                K--;
                continue;
            }
        }while( K > 0 );

    }
    for(auto x : ans){
        cout<<x<<' ';
    }
}

int main() {

    fastIO;
    solve();
}
