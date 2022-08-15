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
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
        a--;
    }
    ll cur = 0;
    vector<bool> seen(N, false);
    deque<ll> deq;
    while(!seen.at(cur)) {
        seen.at(cur) = true;
        deq.push_back(cur);
        cur = A.at(cur);
    }
    ll ans = 0;
    while(!deq.empty()) {
        if(deq.front() == 1) {
            cout << ans << endl;
            return 0;
        }
        deq.pop_front();
        ans++;
    }
    cout << - 1 << endl;
    return 0;
}