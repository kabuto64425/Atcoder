#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A.at(i);
        A.at(i)--;
    }

    vector<bool> seen(N, false);
    deque<ll> log;
    ll cur = 0;
    while(true) {
        if(seen.at(cur)) {
            while(log.front() != cur) {
                log.pop_front();
                K--;
                if(K == 0) {
                    cout << log.front() + 1 << endl;
                    return 0;
                }
            }
            break;
        }

        log.push_back(cur);
        seen.at(cur) = true;
        cur = A.at(cur);
    }

    cout << log.at(K % log.size()) + 1 << endl;
}