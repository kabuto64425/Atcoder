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

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N + 2);
    A.at(0) = -INF;
    for(ll i = 1; i <= N; i++) {
        cin >> A.at(i);
    }
    A.at(N + 1) = INF;
    ll Q;
    cin >> Q;
    vector<ll> B(Q);
    for(ll &b : B) {
        cin >> b;
    }

    sort(A.begin(), A.end());
    for(const ll &b : B) {
        ll index = lower_bound(A.begin(), A.end(), b) - A.begin();
        cout << min(abs(A.at(index) - b), abs(A.at(index - 1) - b)) << endl;
    }
    return 0;
}