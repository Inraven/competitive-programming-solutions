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

vector<int> segtree;
vector<int> arr;


void build(int node, int start, int end) {
    if (start == end) {
        segtree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
    }
}
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        segtree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node+2];
    }
}
int query(int node, int start, int end, int k) {
    if (start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if (segtree[2 * node + 1] >= k) {
        return query(2 * node + 1, start, mid, k);
    } else {
        return query(2 * node + 2, mid + 1, end, k - segtree[2 * node + 1]);
    }
}

void solve() {
    int n;
    cin >> n;
    vi arre(n , 0);
    
    for(int i = 0 ; i < n ; i++){
        cin >> arre[i];
     //   cout<<arre[i]<< ' ' ; 
    }

    vi A(n,0);
    iota(all(A),1);
    arr = vi(n,1);    
    segtree.resize(4*n);
    build(0, 0, n - 1);
    

    int N = n;
    int i = 0;
    int iu = 0;
    
    while(N > 0){
        /*for(int j = 0 ; j < n ; j++){
            cout<<arr[j];
        }cout<<endl;*/

        int curr = (iu + arre[i] - 1)%N;
        int next = (iu + arre[i])%N;

        i = query(0,0,n-1, next+1);
        iu = next;
        if(curr < next) iu--;
        int idx = query( 0, 0 , n - 1 , curr + 1);
        
        //cout<<curr<<' '<<next<<' '<<i<<endl;

        

        update(0 , 0 , n - 1 , idx , 0 );
        
 

        N--;
    }

    cout<<i+1<<endl;

}

int main() {

   // fastIO;
    solve();
}