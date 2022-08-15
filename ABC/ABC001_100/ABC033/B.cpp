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
    ll N;
    cin >> N;
    vector<string> S(N);
    vector<ll> P(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i) >> P.at(i);
    }
    ll sum = 0;
    for(ll i = 0; i < N; i++) {
        sum += P.at(i);
    }
    for(ll i = 0; i < N; i++) {
        if(P.at(i) > sum / 2) {
            cout << S.at(i) << endl;
            return 0;
        }
    }
    cout << "atcoder" << endl;
    return 0;
}