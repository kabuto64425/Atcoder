#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<ll> white(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        white.at(i) = white.at(i - 1);
        if(S.at(i - 1) == '.') {
            white.at(i) += 1;
        }
    }

    ll sumWhite = white.at(N);

    ll ans = INF;

    for(ll i = 0; i <= N; i++) {
        ll leftBlack = i - white.at(i);
        ll rightWhite = sumWhite - white.at(i);
        ans = min(ans, leftBlack + rightWhite);
    }

    cout << ans << endl;

    return 0;
}