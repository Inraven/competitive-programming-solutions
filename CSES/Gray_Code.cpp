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

int binToDec(string str){
    int ans = 0;
    reverse(all(str));
    for(int i = 0;i < SZ(str);i++){
        ans += (1<<i) * (str[i]-'0');
    }
    return ans;
}

void solve() {
    
    int n;
    cin>>n;
    vector<string>ans;
    string cero = "";
    for(int i = 0;i < n;i++)cero+='0';
    ans.push_back(cero);
    
    map<int,bool>mapa;

    mapa[0]=true;

    while(SZ(mapa) < 1LL<<n){
        string x;
        x = ans.back();

        int valor = 0;

        for(int i = 0;i < n;i++){
            x[i] = !(x[i]-'0') + '0';
            valor = binToDec(x);
            if(!mapa.count(valor)) break; 
            
            x[i] = !(x[i]-'0') + '0';
        }

        mapa[valor]=true;
        ans.push_back(x);

    }
    for(auto x : ans)cout<<x<<endl;

}

int main() {

    fastIO;
    solve();
}