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

void solve() {
    int n;
    cin >> n;
    vi A(n , 0);
    for(auto &x : A){
        cin >> x;
    }
    int ans = INT_MAX;
    int l = 0 , r = 0;
    for(int i = 0 ; i + 1 < n ; i++){
        int l = i;
        int r = i + 1;
        if(A[r] < A[l]) swap(l , r);
        if(abs(A[l]-A[r]) <= 1){
            ans = 0;
            break;
        } 
        for(int j = 0 ; j < n ; j++){
            if( j == l || j == r)  continue;
            if( (A[j] >= A[l] && A[j] <= A[r]) || (abs(A[j] - A[l]) <= 1) || (abs(A[j] - A[r]) <= 1) ){
                //cout << l << ' ' << r << ' ' << j << endl;
                if( j < min(l,r) ) 
                    ans = min(ans , min(l,r) - j);
                else 
                    ans = min(ans , j - max(l,r) );
            } 
        }
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans << endl;
}

int main() {

    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}