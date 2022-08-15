#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, string>> pS(M);
    REP(i, M) {
        cin >> pS.at(i).first >> pS.at(i).second;
        pS.at(i).first--;
    }
    ll correct = 0;
    ll penalty = 0;
    vector<pair<bool, ll>> info(N, {false, 0});
    REP(i, M) {
        if(pS.at(i).second == "AC") {
            if(!info.at(pS.at(i).first).first) {
                info.at(pS.at(i).first).first = true;
                correct++;
                penalty += info.at(pS.at(i).first).second;
            }
        } else {
            if(!info.at(pS.at(i).first).first) {
                info.at(pS.at(i).first).second++;
            }
        }
    }
    cout << correct << " " << penalty << endl;
}