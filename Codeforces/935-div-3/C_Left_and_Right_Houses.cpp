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
    string str;
    cin >> n >> str;
    vi sumLeft(n + 2 , 0);
    vi sumRight(n + 2 , 0);

    for(int i = 1 ; i <= n ; i++){
        int x = str[i-1]-'0';
        int y = str[n-i]-'0';
        sumLeft[i] = sumLeft[ i - 1 ] + !(x);
        sumRight[n - i] = sumRight[n - i + 1 ] + y;
    }
    int ans = INT_MAX;
    for(int i = 0 ; i <= n ; i++){
        int l = i;
        int r = (n - i);
        if(sumLeft[i] >= l/2.0 && sumRight[i] >= r/2.0){
            if( abs(n/2.0 - i) < abs(n/2.0 - ans) ){
                ans = i;
            }
        }
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