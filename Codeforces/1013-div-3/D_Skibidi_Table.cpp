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

int pos[2][2] = {{ 0 , 3 },
                 { 2 , 1 }};

ll numberAt(ll x , ll y , ll res , ll n , ll lx , ll ly){
    if(n <= 1) return res;
    ll a = (x >= lx + (n >> 1));
    ll b = (y >= ly + (n >> 1));
    res =  res + ((n * n) / 4) * pos[a][b];
    n >>= 1;
    if(pos[a][b] == 2) lx+=n;
    if(pos[a][b] == 3) ly+=n;
    if(pos[a][b] == 1){ lx+=n; ly+=n;}
    return numberAt(x , y , res, n , lx , ly);
}

pair<ll,ll> position(ll k , ll res , ll n , ll x , ll y){
    
    if(n <= 1) return mp(x , y);
    
    ll v = (n * n) / 4;
    ll a =  res + v * 0;
    ll b =  res + v * 1;
    ll c =  res + v * 2;
    ll d =  res + v * 3;
    n >>= 1;

    if( k >= a && k < b ){
        res = a;
    }else if( k >= b && k < c ){
        res = b;
        x += n;
        y += n;
    }else if( k >= c && k < d ){
        res = c;
        x += n;
    }else{
        res = d;
        y += n;
    }
    return position(k , res, n , x , y);

}

void solve() {
    ll n , q;
    cin >> n >> q;  
    n = (1 << (n));
    for(int i = 0 ; i < q ; i++){
        string op;
        ll x , y , k;
        cin >> op;
        switch(op[1]){
            case '>':
                cin >> x >> y;
                cout << numberAt(x , y , 1 , n , 1 , 1) << endl;
                break;
            case '-':
                cin >> k;
                auto p = position(k , 1 , n , 1 , 1);
                cout << p.f << ' ' << p.s << endl;
                break;
        }
    }

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