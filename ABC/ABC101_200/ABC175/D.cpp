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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    vector<ll> C(N);
    for(ll i = 0; i < N; i++) {
        cin >> P.at(i);
        P.at(i)--;
    }
    for(ll i = 0; i < N; i++) {
        cin >> C.at(i);
    }
    ll ans = -INF;
    for(ll i = 0; i < N; i++) {
        vector<bool> seen(N, false);
        deque<ll> deq;
        ll cur = i;
        ll sum = 0;
        ll sumMax = -INF;
        while(true) {
            if(seen.at(cur)) {
                break;
            }
            seen.at(cur) = true;
            cur = P.at(cur);
            deq.push_back(C.at(cur));
            sum += C.at(cur);
            sumMax = max(sumMax, sum);
        }
        ll s = deq.size();
        ll cycle = K / s;
        ll m = K % s;
        ll temporary = -INF;
        if(cycle >= 1) {
            if(sum >= 0) {
                temporary = max(temporary, (cycle - 1) * sum + sumMax);
            } else {
                temporary = max(temporary, sumMax);
            }
        }
        ll restNum = cycle * sum;
        for(ll j = 0; j < m; j++) {
            restNum += deq.front();
            temporary = max(temporary, restNum);
            deq.pop_front();
        }
        ans = max(ans, temporary);
    }
    cout << ans << endl;
    return 0;
}