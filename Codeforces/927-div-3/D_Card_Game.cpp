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

bool test(V<vi>&beat , vi &visited , V<string> &cards , int turn , char suit){

    if(2 * turn == SZ(cards) ){
        V<vi>ans(turn);
        for(int i = 0 ; i < SZ(visited) ; i++){
            if(visited[i] == -1){
                return false;
            } 
            ans[ visited[i] ].pb(i);
        }
        while(turn--){
            auto &a = cards[ ans[turn][0] ];
            auto &b = cards[ ans[turn][1] ];

            if( (a[0] > b[0] && a[1] == b[1]) || ( a[1] != b[1] && a[1] == suit ) ){
                cout << b << ' ' << a << endl;
            }else cout << a << ' ' << b << endl;

        }

        return true;
    }

    for(int i = 0 ; i < SZ(cards) ; i++){
        if(visited[i] != -1) continue;
        visited[i] = turn;
        for(auto &x : beat[i]){
            if(visited[x] != -1) continue;
            visited[x] = turn;
            bool found = test(beat, visited, cards, turn + 1 , suit);            
            visited[x] = -1;
            if(found) return true;
        }
        visited[i] = -1;
    }
    return false;
}

void solve() {
    int n;
    char suit;
    cin >> n >> suit;

    V<string> cards( 2 * n);
    V<V<int>>beat( 2 * n );
    for(auto &x : cards){
        cin >> x;
    }

    for(int i = 0 ; i < SZ(cards) ; i++){
        for(int j = 0 ; j < SZ(cards) ; j++){
            if(i == j) continue;
            auto &a = cards[i];
            auto &b = cards[j];
            if( a[1] == b[1] || a[1] == suit || b[1] == suit ){
                if( (a[0] > b[0] && a[1] == b[1]) || ( a[1] != b[1] && a[1] == suit ) ){
                    beat[i].pb(j);
                } 
            }
        }
    }

    vi visited(2 * n , -1);
    if( !test(beat, visited, cards , 0 , suit) ) cout << "IMPOSSIBLE" << endl;

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