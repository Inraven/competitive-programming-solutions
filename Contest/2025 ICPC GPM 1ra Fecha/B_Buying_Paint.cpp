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

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
//dir 0 = der , 1 = izq , 2 = abajo , 3 = arriba
void spiral( V<vi> &visit , V<vi>&A , vi &path , int dir, int i , int j){
    if(visit[i][j]) return;
    
    visit[i][j] = 1;
    path.pb( A[i][j] );
    int x = dx[dir];
    int y = dy[dir];
    
    if( visit[i+x][j+y] ){
        for(int k = 0 ; k < 4 ; k++){
            if( !visit[ i+dx[k] ][ j+dy[k]] ){
                x = dx[k];
                y = dy[k];
                dir = k;
            }
        }
    } 

    spiral(visit , A , path , dir , i + x , j + y);
}

void fill( V<vi> &visit , int n){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            visit[i][j] = 0;
        }
    }
}

ll maxSegment( vi &arr ){
    ll ans = 0 , sum = 0;
    for(auto x : arr){
        sum = max(sum , 0LL);
        sum += x;
        ans = max(ans , sum);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;    
    V<vi>A(n + 2 , vi(n + 2, 0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> A[i][j];
        }
    }

    vector< tuple<int,int,int> > starts;
    //dir 0 = der , 1 = izq , 2 = abajo , 3 = arriba
    starts.emplace_back( 1 , 1 , 0 ); starts.emplace_back( 1 , 1 , 2 );
    starts.emplace_back( 1 , n , 1 ); starts.emplace_back( 1 , n , 2 );
    starts.emplace_back( n , 1 , 0 ); starts.emplace_back( n , 1 , 3 );
    starts.emplace_back( n , n , 1 ); starts.emplace_back( n , n , 3 );
    ll ans = 0;
    for(auto &[i , j , dir] : starts){
        vi path;
        V<vi> visit(n + 2, vi(n + 2 , 1) );
        fill(visit , n);
        spiral(visit , A , path , dir , i , j );
        ans = max(ans, maxSegment(path) );
    }
    cout << ans << endl;
}

int main() {

    fastIO;
    solve();
}