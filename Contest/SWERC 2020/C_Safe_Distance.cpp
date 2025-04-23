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

struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int size(int x) { return -e[get(x)]; }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool join(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};


double dist(pair<double , double> A , pair<double , double> B){
    return sqrt( (B.f - A.f)*(B.f - A.f) + (B.s - A.s)*(B.s - A.s) );
}

bool check(const vector< pair<double , double> > &points, double k, int up , int right){

    DSU dsu;
    vector<pair<bool,bool>>borders(SZ(points));
    dsu.init( SZ(points) );

    for(int i = 0 ; i < SZ(points) ; i++){
        
        if( points[i].s + k > up || points[i].f - k < 0 ) borders[dsu.get(i)].f = true;
        if( points[i].f + k > right || points[i].s - k < 0 ) borders[dsu.get(i)].s = true;
    
        if( borders[dsu.get(i)].f && borders[dsu.get(i)].s) return false;
    }

    for(int i = 0 ; i < SZ(points) ; i++){
        for(int j = 0 ; j < SZ(points) ; j++){


            if( dist(points[i] , points[j])  < 2 * k ){
                
                auto a = borders[dsu.get(i)];
                auto b = borders[dsu.get(j)];

                dsu.join(i , j);

                borders[dsu.get(i)].f = max(a.f , b.f);
                borders[dsu.get(i)].s = max(a.s , b.s);

                if( borders[dsu.get(i)].f && borders[dsu.get(i)].s) return false;

            } 
        }    
    }

    return true;

}


void solve() {
    int X , Y;
    cin >> X >> Y;
    swap(X,Y);
    int n;
    cin >> n;
    vector< pair<double , double> > points;
    for(int i = 0 ; i < n ; i++){
        double x , y;
        cin >> x >> y;
        points.emplace_back(x,y);
    }


    ll ini = 1LL;
    ll fin = 1e12+7;
    ll ans = 0; 
     
    while(ini <= fin){
        
        ll mid = (ini+fin)/2LL;

        if( check(points, mid/1e6 , X , Y) ){
            
            ans = mid;
            ini = mid + 1LL;

        }else{

            fin = mid - 1LL;

        }

    }
    cout<<fixed<<setprecision(6)<<(ans/1e6)<<endl;
    
}

int main() {

    fastIO;
    solve();
}