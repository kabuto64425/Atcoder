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
    string S;
    cin >> S;
    ll N = S.length();
    vector<ll> ans(N, 0);
    // →
    ll count = 0;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == 'R') {
            count++;
        } else {
            ans.at(i) += (count) / 2;
            ans.at(i - 1) += (count + 1) / 2;
            count = 0;
        }
    }

    // ←
    count = 0;
    for(ll i = N - 1; i >= 0; i--) {
        if(S.at(i) == 'L') {
            count++;
        } else {
            ans.at(i) += (count) / 2;
            ans.at(i + 1) += (count + 1) / 2;
            count = 0;
        }
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}