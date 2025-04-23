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

typedef priority_queue<pair<double , pi>,vector<pair<double , pi>>,greater<pair<double , pi>>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

constexpr double EPS = 1e-9;
double dist(pi A , pi B){
    return sqrt( (A.f - B.f) * (A.f - B.f) + (A.s - B.s) * (A.s - B.s)  );
}



void solve() {
    int n , m , p;
    cin >> n >> m >> p;
    //judges, repositores, store
    V<pi>judges , repo , store;
    for(int i = 0 ; i < n ; i++){
        int x , y;
        cin >> x >> y;
        judges.emplace_back(x,y);
    }    

    for(int i = 0 ; i < m ; i++){
        int x , y;
        cin >> x >> y;
        repo.emplace_back(x,y);
    }

    for(int i = 0 ; i < p ; i++){
        int x , y;
        cin >> x >> y;
        store.emplace_back(x,y);
    }
    double ans = 0;
    pqg pares;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            pares.push( mp( dist(judges[i] , repo[j]) , mp(i,j) ) );
        }
    }
    vi visitJ(n , 0);
    vi visitR(m , 0);
    while(!pares.empty()){
        auto [i,j] = pares.top().s;
        double dist = pares.top().f;
        pares.pop();

        if(visitJ[i] || visitR[j]) continue;

        ans += dist;
        visitJ[i] = 1;
        visitR[j] = 1;
    }

    for(int i = 0 ; i < n ; i++){
        if(!visitJ[i]) continue;
        for(int j = 0 ; j < p ; j++){
            pares.push( mp( dist(judges[i] , store[j]) , mp(i,j) ) );
        }
    }
    visitJ = vi(n , 0);
    vi visitS(p , 0);
    while(!pares.empty()){
        auto [i,j] = pares.top().s;
        double dist = pares.top().f;
        pares.pop();

        if(visitJ[i] || visitS[j]) continue;

        ans += dist;
        visitJ[i] = 1;
        visitS[j] = 1;
    }
   
    cout<<fixed<<setprecision(11)<<ans;
}

int main() {

    fastIO;
    solve();
}