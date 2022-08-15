#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<ll, ll>> lr(Q);
    REP(i, Q) {
        cin >> lr.at(i).first >> lr.at(i).second;
    }
    vector<ll> account(N, 0);
    for(ll i = 1; i < N; i++) {
            account.at(i) += account.at(i - 1);
        if(S.substr(i - 1, 2) == "AC") {
            account.at(i)++;
        }
    }

    REP(i, Q) {
        cout << account.at(lr.at(i).second - 1) - account.at(lr.at(i).first - 1) << endl;
    }
}