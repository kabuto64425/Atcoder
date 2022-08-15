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
    vector<ll> X(N), Y(N);
    for(ll i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    sort(ALL(X));
    sort(ALL(Y));
    vector<ll> csumX(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        csumX.at(i) = csumX.at(i - 1) + X.at(i - 1);
    }
    ll ansX = INF;
    for(ll i = 1; i <= N; i++) {
        ll sum1 = csumX.at(i - 1);
        ll sum2 = csumX.at(N) - csumX.at(i);
        ll current = 0;
        current += (i - 1) * X.at(i - 1) - sum1;
        current += sum2 - (N - i) * X.at(i - 1);
        ansX = min(ansX, current);
    }
    vector<ll> csumY(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        csumY.at(i) = csumY.at(i - 1) + Y.at(i - 1);
    }
    ll ansY = INF;
    for(ll i = 1; i <= N; i++) {
        ll sum1 = csumY.at(i - 1);
        ll sum2 = csumY.at(N) - csumY.at(i);
        ll current = 0;
        current += (i - 1) * Y.at(i - 1) - sum1;
        current += sum2 - (N - i) * Y.at(i - 1);
        ansY = min(ansY, current);
    }
    cout << ansX + ansY << endl;
    return 0;
}