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
using pi = pair<ll, ll>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+9;
constexpr int MAXN = 1e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

void compute_hash(string const& s , V<ll>&prefix , V<ll>&pows) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for (char c : s) {
        hash_value = (hash_value * p + (c - 'A' + 1) ) % m;
        prefix.pb(hash_value);
        pows.pb(p_pow);
        p_pow = (p_pow * p) % m;
        
    }
    return;
}

vector<ll>prefix,pows;
ll HashSubstring(int a,int b){
    if(a == 0){
        return prefix[b];
    }
    ll m = (prefix[a-1]%MOD * pows[b-a+1]%MOD)%MOD;
    ll x =  prefix[b]-m;
    if(x < 0)x += MOD;
    return x;
}

pi check(int size, int n){
    map<ll , ll>mapa;
    for(int i = 0; i + size - 1 < n; i++){
        
        ll x = HashSubstring(i, i + size - 1);
        //cout << i << ' ' << i + size - 1 << ' ' << x  << endl;
        mapa[x]++;
    }

    for(int i = 0; i + size - 1 < n; i++){
        
        ll x = HashSubstring(i, i + size - 1);
        
        if(  mapa[x] == 1  ){
            return mp(1, i);
        }

    }
    return mp(0, 0);
}

void solve() {
    string str;
    cin >> str;
    
    compute_hash(str, prefix, pows);

    int ini = 1;
    int fin = SZ(str);
    pi ans = mp(SZ(str),0);
    
    while(ini <= fin){
        int mid = (ini+fin)/2;
        auto tp = check(mid,SZ(str));
        //cout << endl << endl;
        if(tp.f){
            //size min
            ans = mp(tp.s,mid);
            fin = mid - 1;
        }else{
            ini = mid + 1;
        }

    }
    //cout<<HashSubstring(2,2)<<" "<<HashSubstring(6,6)<<endl;
    //cout<<ans.f<<" "<<ans.s<<endl;
    cout<<str.substr(ans.f , ans.s)<<endl;
}

int main() {

    fastIO;
    solve();
}