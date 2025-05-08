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
    cin >> k;
    V<ll> arr(k , 0);
    V<ll> cnt(k , 0);
    for(auto &x : arr){
        cin >> x;
    }
    cin >> n;
    V<V<ll>>A(n + 1, V<ll>(k , 0));
    for(int j = 0 ; j < n ; j++){
        for(int i = 0 ; i < k ; i++){
            ll x;
            cin >> x;
            A[j + 1][i] = x + A[j][i];
            cnt[i] += x;
        }
    }
    ll day = 1e12+7;
    ll order = n;
    for(int i = 0 ; i < k ; i++){
        if(cnt[i] == 0) continue;
        ll tempDay = ( arr[i] / cnt[i] );
        day = min(day , tempDay);
    }
    for(int i = 0 ; i < k ; i++){
        arr[i] = arr[i] - (cnt[i] * day );
    }
    ll sum = 0;
    for(ll i = 1 ; i <= n; i++){
        for(ll j = 0 ; j < k ; j++){
            if(A[i][j] > arr[j]){
                order = min(order , i);
            } 
        }
    }

    cout << day + 1 << ' ' << order << endl;


}

int main() {

    fastIO;
    solve();
}