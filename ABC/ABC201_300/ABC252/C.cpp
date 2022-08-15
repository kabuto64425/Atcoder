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
    ll N;
    cin >> N;
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    vector<vector<ll>> v(N, vector<ll>(10));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 10; j++) {
            ll x = (ll)(S.at(i).at(j) - '0');
            v.at(i).at(x) = j;
        }
    }
    vector<vector<ll>> v2(10, vector<ll>(10, 0));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < 10; j++) {
            ; // 何番目;
            v2.at(j).at(v.at(i).at(j))++;
        }
    }
    ll ans = INF;
    for(ll i = 0; i < 10; i++) {
        ll current = 0;
        for(ll j = 0; j < 10; j++) {
            chmax(current, (v2.at(i).at(j) - 1) * 10 + j);
        }
        chmin(ans, current);
    }
    cout << ans << endl;
    return 0;
}