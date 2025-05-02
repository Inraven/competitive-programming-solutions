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
    string str;
    cin >> str;
    vi cnt(128 , 0);    
    for(auto x : str){
        cnt[x]++;
    }
    int a = 0;
    char mid = '.';
    for(int i = 'A' ; i <= 'Z' ; i++){
        if(!cnt[i]) continue;
        if(cnt[i]&1){
            mid = i;
            a++;
        } 
    }
    int n = SZ(str);
    if(a > 1 || (!(n&1) && a)){
        cout << "NO SOLUTION";
        return;
    }
    int l = 0;
    int r = n - 1;
    V<char>ans(n);
    for(int i = 'A' ; i <= 'Z' ; i++){
        if(!cnt[i]) continue;
        while( cnt[i] > 1 ){
            ans[l] = i;
            ans[r] = i;
            cnt[i] -= 2;
            l++;
            r--;
        }
    }
    if(n&1) ans[n/2] = mid;
    for(auto x : ans) cout << x;

}

int main() {

    fastIO;
    solve();
}