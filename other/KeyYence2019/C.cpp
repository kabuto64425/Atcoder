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
    vector<ll> B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    ll ans = 0;
    ll diff = 0;
    ll need = 0;
    vector<ll> v;
    for(ll i = 0; i < N; i++) {
        if(B.at(i) > A.at(i)) {
            ans++;
            need += B.at(i) - A.at(i);
        } else {
            v.push_back(A.at(i) - B.at(i));
        }
        diff += (A.at(i) - B.at(i));
    }
    if(diff < 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(ALL(v), greater<ll>());
    ll M = v.size();
    vector<ll> csum(M + 1, 0);
    for(ll i = 0; i < M; i++) {
        csum.at(i + 1) = csum.at(i) + v.at(i);
    }
    ans += (ll)(lower_bound(ALL(csum), need) - csum.begin());
    cout << ans << endl;
    return 0;
}