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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }

    vector<pair<ll, ll>> Ap(N);
    vector<pair<ll, ll>> Bp(N);
    vector<pair<ll, ll>> sump(N);
    for(ll i = 0; i < N; i++) {
        Ap.at(i) = {-A.at(i), i};
        Bp.at(i) = {-B.at(i), i};
        sump.at(i) = {-A.at(i) - B.at(i), i};
    }

    sort(ALL(Ap));
    sort(ALL(Bp));
    sort(ALL(sump));

    vector<bool> isPassed(N, false);

    ll count = 0;
    for(ll i = 0; i < N; i++) {
        if(count >= X) {
            break;
        }
        if(!isPassed.at(Ap.at(i).second)) {
            isPassed.at(Ap.at(i).second) = true;
            count++;
        }
    }

    count = 0;
    for(ll i = 0; i < N; i++) {
        if(count >= Y) {
            break;
        }
        if(!isPassed.at(Bp.at(i).second)) {
            isPassed.at(Bp.at(i).second) = true;
            count++;
        }
    }

    count = 0;
    for(ll i = 0; i < N; i++) {
        if(count >= Z) {
            break;
        }
        if(!isPassed.at(sump.at(i).second)) {
            isPassed.at(sump.at(i).second) = true;
            count++;
        }
    }

    for(ll i = 0; i < N; i++) {
        if(isPassed.at(i)) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}