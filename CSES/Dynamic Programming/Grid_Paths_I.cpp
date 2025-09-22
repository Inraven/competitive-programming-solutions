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
    V<vi>grid(n + 2 , vi(n + 2 , 1));
    V<vi>dp(n + 2 , vi(n + 2 , 0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            char c;
            cin >> c;
            if(c == '*') grid[i][j] = 0;
        }
    }
    dp[1][1] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(grid[i][j-1]) dp[i][j] += dp[i][j-1];
            if(grid[i-1][j]) dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    cout << (grid[n][n] ? dp[n][n] : 0) << endl;
    
}

int main() {

    fastIO;
    solve();
}