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
    string S;
    string T;
    cin >> S;
    cin >> T;
    ll szero = 0;
    ll tzero = 0;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == '0') {
            szero++;
        }
        if(T.at(i) == '0') {
            tzero++;
        }
    }
    if(szero != tzero) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> zeroS;
    vector<ll> zeroT;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == '0') {
            zeroS.push_back(i);
        }
        if(T.at(i) == '0') {
            zeroT.push_back(i);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < zeroS.size(); i++) {
        if(zeroS.at(i) != zeroT.at(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}