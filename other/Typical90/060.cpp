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
    }
    vector<ll> B;
    vector<ll> P(N);
    for(ll i = 0; i < N; i++) {
        ll cnt = lower_bound(ALL(B), A.at(i)) - B.begin();
        if(cnt == (ll)B.size()) {
            B.push_back(A.at(i));
        } else {
            B.at(cnt) = A.at(i);
        }
        P.at(i) = cnt + 1;
    }
    reverse(ALL(A));
    B.clear();
    vector<ll> Q(N);
    for(ll i = 0; i < N; i++) {
        ll cnt = lower_bound(ALL(B), A.at(i)) - B.begin();
        if(cnt == (ll)B.size()) {
            B.push_back(A.at(i));
        } else {
            B.at(cnt) = A.at(i);
        }
        Q.at(i) = cnt + 1;
    }
    reverse(ALL(Q));
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ans = max(ans, P.at(i) + Q.at(i) - 1);
    }
    cout << ans << endl;
    return 0;
}