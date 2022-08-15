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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    ll a, b;
    cin >> a >> b;
    ll K;
    cin >> K;
    vector<ll> P(K);
    for(ll i = 0; i < K; i++) {
        cin >> P.at(i);
    }
    set<ll> s;
    s.insert(a);
    s.insert(b);
    for(ll i = 0; i < K ; i++) {
        if(s.count(P.at(i))) {
            cout << "NO" << endl;
            return 0;
        }
        s.insert(P.at(i));
    }
    cout << "YES" << endl;
    return 0;
}