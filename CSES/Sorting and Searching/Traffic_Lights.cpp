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
typedef tuple<int,int,int> T; 
typedef priority_queue<T,vector<T>,greater<T> > pqg; ///Min
typedef priority_queue<T> pq; ///Max

void solve() {
    int x,n;
    cin >> x >> n;
    set<int>S;
    multiset<int>MS;
    S.insert(0);
    S.insert(x);
    MS.insert(x);
    while(n--){
        int u; cin >> u;
        auto it = S.lower_bound(u);
        auto it2 = it;
        it2--;
        MS.erase( MS.find(*it - *it2) );
        MS.insert(u - *it2);
        MS.insert(*it - u);
        cout << *--MS.end() << ' ';
        S.insert(u);
    }

    
}

int main() {

    fastIO;
    solve();
}