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
    int n , m , k;
    cin >> n >> m >> k;
    vi A(n , 0), B(m , 0);
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    sort(all(A)); sort(all(B));
    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < m){
        if( abs( A[i] - B[j] ) <= k ){
            i++;
            j++;
            ans++;
        }else if(A[i] > B[j]){
            j++;
        }else{
            i++;
        }
    }
    cout << ans << endl;
}

int main() {

    fastIO;
    solve();
}