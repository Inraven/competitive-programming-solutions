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
    vi arr(n , 0);
    vi maxis(n, 0);
    vi minis(n ,0);
    for(auto &x : arr){
        cin >> x;
    }
    maxis[n-1] = arr[n-1];
    minis[0] = arr[0];
    for(int i = 1 ; i < n ; i++){
        minis[i] = min(minis[i - 1] , arr[i]);
    }
    for(int i = n - 2 ; i >= 0 ; i--){
        maxis[i] = max(maxis[i + 1] , arr[i]);
    }
    string ans = "";
    for(int i = 0 ; i < n ; i++){
        if( (minis[i] == arr[i] && arr[i] <= maxis[i]) || (arr[i] == maxis[i] && arr[i] >= minis[i])) ans += "1";
        else ans +="0";
    }
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