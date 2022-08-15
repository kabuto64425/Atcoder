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
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for(ll &h : H) {
        cin >> h;
    }
    vector<ll> W(M);
    for(ll &w : W) {
        cin >> w;
    }

    sort(H.begin(), H.end());

    vector<ll> odd(N + 1, 0);
    vector<ll> even(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        odd.at(i) += odd.at(i - 1);
        even.at(i) += even.at(i - 1);
        if(i % 2 == 1) {
            odd.at(i) += H.at(i - 1);
        } else {
            even.at(i) += H.at(i - 1);
        }
    }

    ll ans = INF;
    for(ll i = 0; i < M; i++) {
        ll w = W.at(i);
        ll index = lower_bound(H.begin(), H.end(), w) - H.begin();
        index++;
        if(index % 2 == 1) {
            ans = min(ans, even.at(index - 1) - odd.at(index - 1) - w + odd.at(N) - odd.at(index - 1) - even.at(N) + even.at(index - 1));
        } else {
            ans = min(ans, even.at(index - 1) - odd.at(index - 1) + w + odd.at(N) - odd.at(index - 1) - even.at(N) + even.at(index - 1));
        }
    }
    cout << ans << endl;
    return 0;
}