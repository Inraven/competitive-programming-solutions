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

const int NREINAS = 8;
vector<int> sol;
int ans = 0;
V<V<char>>table(NREINAS + 1, V<char>(NREINAS + 1));

inline bool contiene(const vector<int>& v, const int val){
    return find(v.begin(), v.end(), val) != v.end();
}

void reinas(int k, vector<int> col, vector<int> diag45, vector<int> diag135){
    if( k == NREINAS ){
        for(int j=0; j<NREINAS; j++){
            if( table[j+1][sol[j]] == '*' ) return;
        }
        ans++;
    }else{
        for(int j=1; j<=NREINAS; j++)
            if( !contiene(col, j) && !contiene(diag45, j-k) && !contiene(diag135, j+k) ){
                sol[k] = j;

                col.push_back(j);
                diag45.push_back(j-k);
                diag135.push_back(j+k);

                reinas(k+1,col, diag45, diag135);

                col.pop_back();
                diag45.pop_back();
                diag135.pop_back();
            }
    }
}
void solve() {
    
    for(int i = 1 ; i <= NREINAS ; i++){
        for(int j = 1 ; j <= NREINAS ; j++){
            cin >> table[i][j];
        }
    }
    sol.resize(NREINAS);
    reinas(0, vector<int>(), vector<int>(), vector<int>());
    cout << ans << endl;
}

int main() {

    fastIO;
    solve();
}