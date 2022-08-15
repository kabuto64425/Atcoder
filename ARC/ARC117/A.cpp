#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll A, B;
    cin >> A >> B;
    vector<ll> ans(A + B);
    if(A >= B) {
        for(ll i = 0; i < A; i++) {
            ans.at(i) = i + 1;
        }
        for(ll i = 0; i < B - 1; i++) {
            ans.at(A + i) = -(i + 1);
        }
        ans.at(A + B - 1) = -(A * (A + 1) / 2 - B * (B - 1) / 2);
    } else {
        for(ll i = 0; i < B; i++) {
            ans.at(i) = -(i + 1);
        }
        for(ll i = 0; i < A - 1; i++) {
            ans.at(B + i) = i + 1;
        }
        ans.at(A + B - 1) = B * (B + 1) / 2 - A * (A - 1) / 2;
    }

    for(const ll x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}