//Author: AngelRuiz
// INCOMPLETE
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
const int dx[4] = {1, 0, -1, 0}, 
          dy[4] = {0, 1, 0, -1};

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

constexpr int N = 7;
int sol = 0;
V<vi>visited(N + 1 , vi(N + 1, 0));

bool limites(int i , int j){
    if(i < 1 || j < 1 || j > N || i > N) return false;
    return true;
}

void test(int i ,int j, int cnt){
    if(cnt > N*N) return;
    if(i == N && j == 1 && cnt != N*N) return;
    if(i == N && j == 1 && cnt == N*N){
        //cout << sol << endl;
        sol++;
        return;
    }
    for( int k = 0 ; k < 4 ; k++){
        int x = dx[k];
        int y = dy[k];
        if(!limites(i + x, j + y)) continue;
        if( visited[i+x][j+y] ) continue;
        visited[i+x][j+y] = 1;
        test(i+x, j+y, cnt + 1);
        visited[i+x][j+y] = 0;
    }
    return;
}

void solve() {
    visited[1][1] = 1;
    test(1,1,1);
    cout << sol << endl;
}

int main() {

    fastIO;
    solve();
}