// Problem solved by Angel Ruiz
 
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
    V<ll> arr(n , 0);
    ll sum1 = 0 , sum2 = 0;
    ll ans = -1e9;
    for(auto &x : arr){
        cin >> x;
        ans = max(ans , x);
    } 
    int i = 0;
    while(i < n){
        while( i < n && arr[i] >= 0 ){
            sum1 += arr[i];
            ans = max(ans , sum1);
            i++;
        } 
        while( i < n && arr[i] <= 0 ){
            sum2 += arr[i];
            i++;
        } 
        if( sum1 + sum2 >= 0 ) sum1 += sum2;
        else sum1 = 0;
        sum2 = 0;
    }
    cout << ans << endl;
}
 
int main() {
 
    fastIO;
    solve();
}