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

ll xd(int i, V<ll> &arr , ll s1 , ll s2){
    if(i == SZ(arr)){
        return  abs(s1 - s2);
    }
    return min( xd(i + 1 , arr , s1 + arr[i] , s2) , xd(i + 1 , arr , s1 , s2 + arr[i]) );
}

void solve() {
    int n;
    cin >> n;
    V<ll> arr(n , 0);
    for(auto &x : arr) cin >> x;
    cout << xd(0, arr , 0 , 0) << endl;
}

int main() {

    fastIO;
    solve();
}