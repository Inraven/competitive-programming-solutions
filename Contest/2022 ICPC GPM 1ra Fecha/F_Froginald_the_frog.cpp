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
#define sz(x) (int)x.size()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e6+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

const int N = 2;
struct Matrix {
    ll a[N][N] = {{0,0},{0,0}};
    Matrix operator*(const Matrix& other) {
        Matrix product;
        
        product.a[0][0] = (a[0][0] * other.a[0][0] + a[0][1] * other.a[1][0]) % MOD;
        product.a[0][1] = (a[0][0] * other.a[0][1] + a[0][1] * other.a[1][1]) % MOD;
        product.a[1][0] = (a[1][0] * other.a[0][0] + a[1][1] * other.a[1][0]) % MOD;
        product.a[1][1] = (a[1][0] * other.a[0][1] + a[1][1] * other.a[1][1]) % MOD;

        return product;
    }
};

Matrix expo_power(Matrix a, long long k, long long ini) {
    Matrix product;
    for (int i = 0; i < N; ++i) product.a[i][i] = ini;

    while (k > 0) {
        if ((k & 1)) {
            product = product * a;
        }
        a = a * a;
        k >>= 1;
    }
    return product;
}
ll A[MAXN];    
void solve() {
    ll n , m;
    
    cin >> n >> m;
    
    Matrix test;
    test.a[0][0] = 1;
    test.a[0][1] = 1;
    test.a[1][0] = 1;
    test.a[1][1] = 0;
    

    for(int i = 0 ; i < m ; i++){
        cin >> A[i];
        A[i]++;
    }            
        
    sort(A, A + m);
    
    ll fib = 1;
    
    ll last = 0;

    for(int i = 0 ; i < m ; i++){
        
        ll act = A[i] - last + 1;

        Matrix res = expo_power( test , act , fib );

        fib = (res.a[0][1] - res.a[1][1]);
        if(fib < 0) fib += MOD;
        
        last = A[i];
    }

    Matrix res = expo_power(test , n - last + 1 , fib);
    cout<<res.a[0][1];    
}

int main() {

    fastIO;
    solve();
}