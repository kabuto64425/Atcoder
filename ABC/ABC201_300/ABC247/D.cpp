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
    vector<ll> o(Q), x(Q), c(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> o.at(i);
        if(o.at(i) == 1) {
            cin >> x.at(i) >> c.at(i);
        }
        if(o.at(i) == 2) {
            cin >> c.at(i);
        }
    }
    deque<pair<ll, ll>> deq;
    for(ll i = 0; i < Q; i++) {
        if(o.at(i) == 1) {
            deq.push_back({x.at(i), c.at(i)});
        }
        if(o.at(i) == 2) {
            ll ans = 0;
            ll rest = c.at(i);
            while(rest > 0) {
                pair<ll, ll> p = deq.front();
                deq.pop_front();
                ll x = p.first;
                ll c = p.second;
                ll num = min(rest, c);
                ans += x * num;
                rest -= num;
                c -= num;
                if(c != 0) {
                    deq.push_front({x, c});
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}