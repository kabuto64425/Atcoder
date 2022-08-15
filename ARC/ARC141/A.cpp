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
    ll T;
    cin >> T;
    vector<ll> c(T);
    for(ll i = 0; i < T; i++) {
        cin >> c.at(i);
    }
    for(ll test = 0; test < T; test++) {
        string s = to_string(c.at(test));
        ll N = s.length();
        for(ll i = 1; i <= 9; i++) {
            if(N % i != 0) {
                continue;
            }
            string t;
            for(ll j = 0; j < i; j++) {
                t += s.at(j);
            }
            ll x = stoi(t);
            for(ll j = 0; j < 10 and x > 0; j++) {

                
                x--;
            }
        }
    }
    return 0;
}