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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<ll, ll>> lr(Q);
    REP(i, Q) {
        cin >> lr.at(i).first >> lr.at(i).second;
    }
    vector<ll> count(N, 0);
    FOR(i, 1, N - 1) {
        count.at(i) = count.at(i - 1);
        if(S.at(i - 1) == 'A' && S.at(i) == 'C') {
            count.at(i)++;
        }
    }
    REP(i, Q) {
        cout << count.at(lr.at(i).second - 1) - count.at(lr.at(i).first - 1) << endl;
    }
}