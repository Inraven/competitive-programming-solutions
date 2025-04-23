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

V<ll> arr;
bool bin(int ini , int fin , int idx){
    if(idx < ini || idx > fin) return false;

    int mid = (ini + fin) / 2;

    if(mid == idx) return true;
    
    if(arr[mid] > arr[idx]){
        return bin(ini , mid - 1 , idx);
    }else{  
        return bin(mid + 1 , fin, idx);
    }

}

void solve() {
    ll n , m , a , c , xo;
    cin >> n >> m >> a >> c >> xo;

    arr.pb(xo);
    for(int i = 1 ; i <= n ; i++){
        //3 6 1 4 7
        arr.pb( ((a%m * arr.back()%m)%m + c%m) % m );
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        //cout<<arr[i]<<' ';
        if(bin(1, n , i)){
            ans++;
            //cout<<arr[i]<<' ';
        } 
    }
    cout<<ans<<endl;
}

int main() {

    fastIO;
    solve();
}