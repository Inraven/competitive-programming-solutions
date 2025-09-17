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
    int q;
    cin >> q;
    deque<ll>arr;
    bool rv = false;
    ll r1 = 0;
    ll r2 = 0;
    ll S = 0;
    ll n = 0;
    while(q--){
        ll op , x;
        cin >> op;
        switch(op){
            case 1:
                ll last;
                if(rv){
                    last = arr.front();
                    arr.pop_front();
                    arr.push_back(last);
                }else{
                    last = arr.back();
                    arr.pop_back();
                    arr.push_front(last);
                }
                
                r2 += - S + last * n;
                r1 +=   S - last * n;
                break;
            case 2:
                swap(r1 , r2);
                rv = !rv;
                break;
            case 3:
                cin >> x;
                n++;
                S += x;
                r1 += (x * n);
                r2 += S;

                rv ? arr.push_front(x) : arr.push_back(x);

                break;            
        }
        cout << r1 << endl;
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