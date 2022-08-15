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
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(11000, false));
    dp.at(0).at(0) = true;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j <= 10000; j++) {
            dp.at(i + 1).at(j) = dp.at(i + 1).at(j) | dp.at(i).at(j);
            if(j + A.at(i) <= 10000) {
                dp.at(i + 1).at(j + A.at(i)) = dp.at(i + 1).at(j + A.at(i)) | dp.at(i).at(j);
            }
        }
    }
    if(dp.at(N).at(S)) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}