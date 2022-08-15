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
    vector<vector<bool>> dp(N + 1, vector<bool>(110000));
    vector<vector<pair<ll, ll>>> pre(N + 1, vector<pair<ll, ll>>(110000));
    dp.at(0).at(0) = true;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j <= 100000; j++) {
            if(j + A.at(i) <= 100000) {
                dp.at(i + 1).at(j + A.at(i)) = dp.at(i + 1).at(j + A.at(i)) | dp.at(i).at(j);
                if(dp.at(i).at(j)) {
                    pre.at(i + 1).at(j + A.at(i)) = {j, 1};
                }
            }
            if(j + B.at(i) <= 100000) {
                dp.at(i + 1).at(j + B.at(i)) = dp.at(i + 1).at(j + B.at(i)) | dp.at(i).at(j);
                if(dp.at(i).at(j)) {
                    pre.at(i + 1).at(j + B.at(i)) = {j, 2};
                }
            }
        }
    }
    if(!dp.at(N).at(S)) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<ll> ans;
    ll price = S;
    for(ll i = N; i >= 1; i--) {
        pair<ll, ll> v = pre.at(i).at(price);
        price = v.first;
        ans.push_back(v.second);
    }
    reverse(ALL(ans));
    for(ll i = 0; i < N; i++) {
        if(ans.at(i) == 1) {
            cout << "A";
        } else if(ans.at(i) == 2) {
            cout << "B";
        }
    }
    cout << endl;

    return 0;
}