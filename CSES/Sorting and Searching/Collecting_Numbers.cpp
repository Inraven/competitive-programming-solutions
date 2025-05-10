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
    vi pos(n + 2 , 0);
    vi arr(n , 0);
    vi visit(n , 0);
    pos[n+1] = -1;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        arr[i] = x;
        pos[x] = i; 
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(!visit[i]){
            ans++;
            int curr = i;
            int currN = arr[i];
            while( curr < pos[currN + 1] ){
                visit[curr] = 1;
                curr = pos[currN + 1];
                currN++;
            }
            visit[ curr ] = 1;
        }        
    }
    cout << ans << endl;
 
}
 
int main() {
 
    fastIO;
    solve();
}