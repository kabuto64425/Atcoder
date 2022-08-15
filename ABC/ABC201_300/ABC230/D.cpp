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
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> LR(N);
    for(ll i = 0; i < N; i++) {
        cin >> LR.at(i).first >> LR.at(i).second;
    }
    for(ll i = 0; i < N; i++) {
        swap(LR.at(i).first, LR.at(i).second);
    }
    sort(ALL(LR));
    for(ll i = 0; i < N; i++) {
        swap(LR.at(i).first, LR.at(i).second);
    }
    ll ans = 0;
    ll current = 0;
    for(ll i = 0; i < N; i++) {
        if(LR.at(i).first <= current) {
            continue;
        }
        ans++;
        current = LR.at(i).second + D - 1;
    }
    cout << ans << endl;
    return 0;
}