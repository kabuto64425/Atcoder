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
    ll L, Q;
    cin >> L >> Q;
    vector<ll> c(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> c.at(i) >> x.at(i);
    }
    vector<ll> cuts;
    cuts.push_back(0);
    cuts.push_back(L);
    for(ll i = 0; i < Q; i++) {
        if(c.at(i) == 1){
            cuts.push_back(x.at(i));
        }
    }
    sort(ALL(cuts));
    ll N = cuts.size();
    vector<ll> len(N - 1);
    for(ll i = 1; i < N; i++) {
        len.at(i - 1) = cuts.at(i) - cuts.at(i - 1); 
    }
    dsu d(N - 1);
    stack<ll> s;
    for(ll i = Q - 1; i >= 0; i--) {
        if(c.at(i) == 1) {
            ll j = lower_bound(ALL(cuts), x.at(i)) - cuts.begin();
            ll lenSum = len.at(d.leader(j - 1)) + len.at(d.leader(j));
            d.merge(j - 1, j);
            len.at(d.leader(j)) = lenSum;
        } else {
            ll j = lower_bound(ALL(cuts), x.at(i)) - cuts.begin();
            s.push(len.at(d.leader(j - 1)));
        }
    }
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}