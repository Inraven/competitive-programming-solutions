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
typedef priority_queue<ll> pq; ///Max

void solve() {
    ll a ,b , s1, s2,s3, ini, fin;
    cin >> a >> b >> s1 >> s2 >> s3 >> ini >> fin;
    pq test;
    for(int i = 1 ; i <= 100 && a - 2*i > 0 && b - 2*i > 0 ; i++){
        test.push((a - 2*i) * (b - 2*i) * i);
    }
    ll start = ini / test.top();
    ll end = fin / test.top();
    
    if(start > end)swap(start,end);
   
    ll mayor = test.top();
    test.pop();
    ll mediano = test.top();
    test.pop();
    ll menor = test.top();
   
  //  cout<<start<<" "<<end<<endl;
    
    for(int i = start ; i <= end ; i++){
        ll totalSupuesto = i * mayor + s1;
     //   cout<<totalSupuesto<<endl;
        if(totalSupuesto < ini || totalSupuesto > fin) continue;
        if( totalSupuesto%mediano == s2 && totalSupuesto%menor == s3 ){
            cout<<totalSupuesto<<endl;
            return;
        }

    }
  
}

int main() {

    fastIO;
    solve();
}