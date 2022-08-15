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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    vector<ll> x(Q), k(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> x.at(i) >> k.at(i);
    }
    map<ll, vector<ll>> m;
    for(ll i = 0; i < N; i++) {
        m[a.at(i)].push_back(i);
    }
    for(ll i = 0; i < Q; i++) {
        if(m[x.at(i)].size() >= k.at(i)) {
            cout << m[x.at(i)].at(k.at(i) - 1) + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}