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
    cin>>n;
    vector<vector<ll>>dp( 2e5+7, vector<ll>( 2e2+7, 0));
    
    dp[1][0] = 1;
    string str;
    cin >> str;
    str = '#' + str;
    //cin>>x;
    
    for(int j = 0;j*j <= n;j++){
                
        
        for(int i = 1;i <= 1+n+j;i++){
            
            if(i <= n && str[i] == '#') continue;

            if(i - j - 1 >= 0 && j - 1 >= 0)
                dp[i][j] += (i - j - 1 > n ? 0 : dp[i - j - 1][j - 1]) + ( i - 1 > n ? 0 : dp[i - 1][j]);
            else    
                dp[i][j] += ( i - 1 > n ? 0 : dp[i - 1][j]);
       
            dp[i][j] %= MOD;
        }    
 
    }
    ll ans = 0;
    for(int j = 0; j*j <= n; j++){
        for(int i = 1;i <= 1+n+j;i++){
            if(i > n){
                ans += dp[i][j];
                ans %= MOD; 
            } 
           // cout<<dp[i][j]<<" ";
        }
       // cout<<endl;
    }
    cout<<ans<<endl;
    
}

int main() {

    fastIO;
    solve();
}