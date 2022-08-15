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
    ll Q;
    cin >> Q;
    vector<ll> t(Q), x(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> t.at(i) >> x.at(i);
    }
    deque<ll> deq;
    for(ll i = 0; i < Q; i++) {
        if(t.at(i) == 1) {
            deq.push_front(x.at(i));
        } else if(t.at(i) == 2) {
            deq.push_back(x.at(i));
        } else {
            cout << deq.at(x.at(i) - 1) << endl;
        }
    }
    return 0;
}