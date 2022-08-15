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
    vector<ll> x(N), y(N);
    for(ll i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i);
    }
    set<pair<ll, ll>> s;
    for(ll i = 0; i < N ; i++) {
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            ll xi = x.at(i);
            ll yi = y.at(i);
            ll xj = x.at(j);
            ll yj = y.at(j);
            ll dx = xj - xi;
            ll dy = yj - yi;
            ll g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            s.insert({dx, dy});
        }
    }
    cout << s.size() << endl;
    return 0;
}