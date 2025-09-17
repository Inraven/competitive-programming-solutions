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
    int n , area;
    cin >> n >> area;
    int p = 2 * (area + 1);
    vector<pair<int,int>>ans,ans2;
    p = p - n;    
    int N = n;
    int x = 0 , y = 0;
    bool aux = true;

    if( n/2 - 1 > area){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    int cnt = 0;
    while( n > 2 ){
        ans.push_back({x,y});
        ans2.push_back({x+1,y});
        //cout << x << ' ' << y << endl;
        //cout << x + 1 << ' ' << y << endl;
        cnt+=2;
        if(aux) x++;
        else x--;
        aux = !aux;
        y++;
        n-=2;
    
    }
    p /= n;
    y+= p;
    
    if(n == 2){
        ans.push_back({x,y});
        ans2.push_back({x+1,y});
        //cout << x << ' ' << y << endl;
        //cout << x + 1 << ' ' << y << endl;
    }else{
        ans2.push_back({x,y});
        //cout << x + aux << ' ' << y << endl;
    }
    
    for(auto [x,y] : ans){
        cout<<x<<' '<<y<<endl;
    }
    for(int i = SZ(ans2)-1;i >= 0;i--){
        cout<<ans2[i].first<<' '<<ans2[i].second<<endl;
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