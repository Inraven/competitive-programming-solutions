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

vi compress(string &str){

    char last = str[0];
    int cnt = 0;
    vi ans ;
    for(auto x : str){
        if(last != x){
            ans.pb(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
        last = x;
    }
    if(cnt) ans.pb(cnt);
    return ans;
}

void solve() {
    string str1 , str2;
    cin>> str1 >> str2;
    vi s1 = compress(str1);
    vi s2 = compress(str2);
    if(SZ(s1) != SZ(s2) || str1[0] != str2[0]){
        cout << "NO" << endl;
        return;
    }

    for(int i = 0 ; i < SZ(s1) ; i++){
        if( 2 * s1[i] < s2[i] || s1[i] > s2[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    

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