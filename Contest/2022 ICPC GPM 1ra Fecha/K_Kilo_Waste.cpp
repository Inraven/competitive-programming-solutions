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

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
vi dp(MAXN+7, -1);
vi A;
int calc(int num ){
    if( num <= 0 ){
        return abs(num);
    }
    if( dp[num] != -1){
        return dp[num];
    }
    int aux = INT_MAX;
    for(int i = 0 ; i < A.size() ; i++){
        int x = calc( num - A[i] );
        aux = min( aux , x );
    }
    return dp[num] = aux;
}

void solve() {
    int n , m;
    cin >> n >> m;

    A = vi(m,0);
    for(auto &x : A){
        cin >> x;
    }
    for(int i = 0 ; i < n ; i++){
        int q;
        cin >> q;
        cout<<calc(q)<<endl;
    }
}

int main() {

    fastIO;
    solve();
}