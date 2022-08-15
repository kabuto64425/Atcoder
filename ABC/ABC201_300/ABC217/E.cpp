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
    deque<ll> deq;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    REP(t, Q) {
        ll q;
        cin >> q;
        if(q == 1) {
            ll x;
            cin >> x;
            deq.push_back(x);
        } else if(q == 2) {
            if(pq.empty()) {
                cout << deq.front() << endl;
                deq.pop_front();
            } else {
                cout << pq.top() << endl;
                pq.pop();
            }
        } else if(q == 3) {
            while(!deq.empty()) {
                pq.push(deq.front());
                deq.pop_front();
            }
        }
    }
    return 0;
}