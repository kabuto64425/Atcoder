#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> sum(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        if(i % 2 == 1) {
            sum.at(i) = sum.at(i - 1) + A.at(i - 1);
        } else {
            sum.at(i) = sum.at(i - 1) - A.at(i - 1);
        }
    }

    map<ll, ll> map;
    for(ll i = 0; i <= N; i++) {
        map[sum.at(i)]++;
    }

    ll ans = 0;

    for (auto elm : map) {
        ans += (elm.second * (elm.second - 1)) / 2;
    }

    cout << ans << endl;

    return 0;
}