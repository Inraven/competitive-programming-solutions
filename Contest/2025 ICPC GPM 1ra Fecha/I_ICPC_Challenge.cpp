#include <bits/stdc++.h>
#define SZ(x) (int)x.size()
#define endl '\n'
using namespace std;
const int MAXN = 1e5 + 7;
int in[MAXN], out[MAXN], t = 0;
void dfs(int u , int p, vector<vector<int>>&g, vector<int>&tour , vector<int>&A ){

    in[u] = ++t;
    tour.push_back( A[u - 1] );
    for(auto &v : g[u]){
        if(v != p) dfs(v , u , g, tour , A);
    }
    tour.push_back( A[u - 1] );
    out[u] = ++t;

}

struct SegmentTree{
    int n;
    vector< map<int, int> >tree;
    SegmentTree( const vector<int>&arr ){
        n = arr.size();
        tree.resize( 4 * n );
        build(1 , 0 , n - 1 , arr);
    }

    void build(int node , int l , int r , const vector<int>& arr){
        if(l == r){
            tree[node][ arr[r] ]++;
        }else{
            int mid = (l + r) / 2;
            build(2 * node , l , mid , arr);
            build(2 * node + 1 , mid + 1 , r , arr);
            for(auto [k , cnt] : tree[2 * node] ){
                tree[node][k] += cnt;
            }
            for(auto [k , cnt] : tree[2 * node + 1] ){
                tree[node][k] += cnt;
            }

        }
    }

    int query(int node , int l , int r , int ql , int qr, int x){
        if( r < ql || l > qr ) return 0;
        
        if( l == r ){
            return tree[node][x];
        }
        if( ql <= l && r <= qr ){
            return tree[node][x];
        }

        int mid = (l + r) / 2;
        int left = query(2 * node , l , mid , ql , qr , x);
        int right = query(2 * node + 1 , mid + 1 , r , ql , qr , x );
        return left + right;
    }
    int query(int l , int r , int x){
        return query(1 , 0 , n - 1 , l , r, x);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n , q;
    cin >> n >> q;
    vector<int> A(n , 0);
    for(auto &x : A) cin >> x;
    vector<vector<int>>g(n + 1 );

    for(int i = 0 ; i < n - 1 ; i++){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int>tour;
    dfs(1 , 0 , g ,tour , A );
    SegmentTree st(tour);

    while(q--){
        int u , x;
        cin >> u >> x;
        int l = in[u]-1  ;
        int r = out[u]-1 ;
        cout << st.query(l , r , x) / 2  << endl;
    }

}
