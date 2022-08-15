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
    vector<pair<ll, ll>> CP(N);
    for(pair<ll, ll> &cp : CP) {
        cin >> cp.first >> cp.second;
    }
    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> LR(Q);
    for(pair<ll, ll> &lr : LR) {
        cin >> lr.first >> lr.second;
    }

    vector<ll> csum1(N + 1, 0);
    vector<ll> csum2(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        csum1.at(i) += csum1.at(i - 1);
        csum2.at(i) += csum2.at(i - 1);
        if(CP.at(i - 1).first == 1) {
            csum1.at(i) += CP.at(i - 1).second;
        } else {
            csum2.at(i) += CP.at(i - 1).second;
        }
    }

    for(const pair<ll, ll> &lr : LR) {
        cout << csum1.at(lr.second) - csum1.at(lr.first - 1) << " " << csum2.at(lr.second) - csum2.at(lr.first - 1) << endl;
    }
    return 0;
}