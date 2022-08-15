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
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(110000, 0));
    vector<vector<ll>> prev_price(N + 1, vector<ll>(110000, 0));
    dp.at(0).at(0) = true;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 0; j <= S; j++) {
            if(j - A.at(i - 1) >= 0) {
                dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j - A.at(i - 1));
                if(dp.at(i - 1).at(j - A.at(i - 1))) {
                    prev_price.at(i).at(j) = j - A.at(i - 1);
                }
            }
            if(j - B.at(i - 1) >= 0) {
                dp.at(i).at(j) = dp.at(i).at(j) | dp.at(i - 1).at(j - B.at(i - 1));
                if(dp.at(i - 1).at(j - B.at(i - 1))) {
                    prev_price.at(i).at(j) = j - B.at(i - 1);
                }
            }
        }
    }
    stack<char> cs;
    if(dp.at(N).at(S)) {
        ll cur_price = S;
        for(ll i = N; i >= 1; i--) {
            if(prev_price.at(i).at(cur_price) == cur_price - A.at(i - 1)) {
                cs.push('A');
            } else if(prev_price.at(i).at(cur_price) == cur_price - B.at(i - 1)) {
                cs.push('B');
            }
            cur_price = prev_price.at(i).at(cur_price);
        }
        while(!cs.empty()) {
            cout << cs.top();
            cs.pop();
        }
        cout << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}