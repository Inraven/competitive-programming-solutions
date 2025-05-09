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
    ll n , m;
    cin >> n >> m;
    V<ll> arr(n , 0);
    for(auto &x : arr){
        cin >> x;
    } 
    string str;
    cin >> str;
    ll total = 1;
    ll l = 0 , r = n - 1;
    for(int i = 0 ; i < SZ(str) - 1 ;i++){
        char &op = str[i];
        if(op == 'L') l++;
        else r--;
    }
    total = arr[r];
    vi ans;
    for(int i = SZ(str) - 2 ; i >= 0 ;i--){
        char &op = str[i];
        ans.pb(total % m);
        if(op == 'L'){
            total = (total * arr[--l]) % m ;
        }else{
            total = (total * arr[++r]) % m ;
        } 
    }
    ans.pb(total % m);
    reverse(all(ans));
    for (auto x : ans ) cout << x << ' ';
    cout << endl;
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