#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

bool solve(const ll mid, const ll N, const ll K, const ll L, const vector<ll> A) {
    ll other = L;
    ll loop = 0;
    for(ll i = 0; i < K; i++) {
        ll length = 0;
        while(length < mid and loop <= N) {
            length += (A.at(loop + 1) - A.at(loop));
            other -= (A.at(loop + 1) - A.at(loop));
            loop++;
        }
        if(other < mid) {
            return false;
        }
    }
    return true;
}

int main(){
    ll N, L;
    cin >> N >> L;
    ll K;
    cin >> K;
    vector<ll> A(N + 2);
    A.at(0) = 0;
    for(ll i = 1; i <= N; i++) {
        cin >> A.at(i);
    }
    A.at(N + 1) = L;

    ll ok = 0;
    ll ng = 1000000001;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, N, K, L, A)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}