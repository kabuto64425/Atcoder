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
    vector<pair<ll, ll>> LR(M);
    for(pair<ll, ll> &lr : LR) {
        cin >> lr.first >> lr.second;
    }
    ll ans = 0;
    for(ll i = 0; i <= M - 2; i++) {
        for(ll j = i + 1; j <= M - 1; j++) {
            if(LR.at(i).first < LR.at(j).first) {
                if(LR.at(i).second > LR.at(j).first and LR.at(i).second < LR.at(j).second) {
                    ans++;
                }
            }
            if(LR.at(j).first < LR.at(i).first) {
                if(LR.at(j).second > LR.at(i).first and LR.at(j).second < LR.at(i).second) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}