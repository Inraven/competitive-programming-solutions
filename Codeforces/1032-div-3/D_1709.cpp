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
    cin >> n;
    vi A(n);
    vi B(n);
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    int cnt = 0;
    V<pi> moves;
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n - 1 ; i++){
            if(A[i] > A[i+1]){
                swap(A[i] , A[i+1]);
                moves.emplace_back(1, i + 1);
            }
        }
    }

    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n - 1 ; i++){
            if(B[i] > B[i+1]){
                swap(B[i] , B[i+1]);
                moves.emplace_back(2, i + 1);
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(A[i] > B[i]){
            swap(A[i] , B[i]);
            moves.emplace_back(3 , i + 1);
        }
    }
    cout << SZ(moves) << endl;

    for(auto [op , i] : moves){
        cout << op << ' ' << i << endl;
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