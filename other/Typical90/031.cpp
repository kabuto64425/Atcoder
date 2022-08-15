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
    ll N;
    cin >> N;
    vector<ll> W(N);
    for(ll &w : W) {
        cin >> w;
    }
    vector<ll> B(N);
    for(ll &b : B) {
        cin >> b;
    }

    vector<vector<ll>> grundy(51, vector<ll>(2600));
    for(ll w = 0; w <= 50; w++) {
        for(ll b = 0; b <= 1500; b++) {
            vector<ll> mex(1555, 0);
            if(w >= 1) {
                mex.at(grundy.at(w - 1).at(b + w)) = 1;
            }
            if (b >= 2) {
                for(ll k = 1; k <= (b / 2); k++) {
                    mex.at(grundy.at(w).at(b - k)) = 1;
                }
            }
            for (ll k = 0; k < 1555; k++) {
                if (mex.at(k) == 0) {
                    grundy.at(w).at(b) = k;
                    break;
                }
            }
        }
    }

    ll judge = 0;
    for(ll i = 0; i < N; i++) {
        judge ^= grundy.at(W.at(i)).at(B.at(i));
    }

    if(judge == 0) {
        cout << "Second" << endl;
        return 0;
    }

    cout << "First" << endl;
    return 0;
}