#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> A(N);
    for(auto &a : A) {
        cin >> a;
    }
    vector<string> B(M);
    for(auto &b : B) {
        cin >> b;
    }
    for(ll i = 0; i <= N - M; i++) {
        for(ll j = 0; j <= N - M; j++) {
            bool flag = true;
            for(ll k = 0; k <= M - 1; k++) {
                for(ll l = 0; l <= M - 1; l++) {
                    if(A.at(i + k).at(j + l) != B.at(k).at(l)) {
                        flag = false;
                    }
                }
            }
            if(flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}