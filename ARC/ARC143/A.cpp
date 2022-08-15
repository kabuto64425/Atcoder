#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    vector<ll> v;
    v.push_back(A);
    v.push_back(B);
    v.push_back(C);
    sort(ALL(v));
    ll large = v.at(2);
    ll middle = v.at(1);
    ll small = v.at(0);
    ll x = small + middle - large;
    if(x < 0) {
        cout << -1 << endl;
        return 0;
    }
    large -= x;
    middle -= x;
    small -= x;
    if(small + middle != large) {
        cout << -1 << endl;
        return 0;
    }
    cout << x + large << endl;
    return 0;
}