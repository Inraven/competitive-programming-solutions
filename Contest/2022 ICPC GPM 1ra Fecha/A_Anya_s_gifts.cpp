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
#define sz(x) (int)x.size()
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
    
    ll n;
    cin >> n;
    V<ll> A(n,0);
    ll t = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        t ^= A[i];
    }
    V<ll> XD(55 , 0);
    for(auto &num : A){
        for(int i = 50 ; i >= 0 ; i--){
            if( (t >> i) & 1 ) continue;
            if( !((num >> i) & 1) ) continue;
            if( XD[i] == 0 ){
                XD[i] = num;
                break;
            }else num ^= XD[i];
        }
    }
    ll aux = 0 , ans = 0;
    for(int i = 50 ; i >= 0 ; i--){
        
        if( (!((aux >> i) & 1)) && XD[i]) aux ^= XD[i];
        if( (t >> i) & 1 )   ans += 1LL << i;
        else if( (aux >> i) & 1 ) ans += 1LL << (i+1);  
        //cout<<i<<" : "<<(t>>i & 1)<<' '<<aux<<' '<<' '<<((aux >> i)&1)<<' '<<ans<<endl; 
    }
    cout<<ans;
}

int main() {

    fastIO;
    solve();
}