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
    int n , k;
    cin >> n >> k;
    map<string , pi> cnt;
    cin.ignore();
    
    
    for(int i = 0 ; i < 3*n ; i++){
        string str;
        getline(cin , str);
        cnt[str].f++;
        cnt[str].s = i;
    }
    
    vector<tuple< int , int , string >> output;
    for(auto &[str , c] : cnt){
        
        output.emplace_back( c.f , c.s , str  );
        
    }

    sort( all(output) , greater<tuple< int , int , string >>());
    
    for(int i = 0 ; i < k && i < output.size() ; i++){
        auto &[c , pos , str] = output[i];
        cout << str << endl;        
    }

    
}

int main() {

    fastIO;
    solve();
}