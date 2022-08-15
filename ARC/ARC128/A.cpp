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
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> ans(N);
    ll j = 0;
    ll c = 1;
    for(ll i = 0; i < N - 1; i++) {
        if(A.at(i) > A.at(i + 1)) {
            c++;
        } else {
            if(c >= 2) {
                ans.at(i) = 1;
                ans.at(j) = 1;
            }
            j = i + 1;
            c = 1;
        }
    }
    if(c >= 2) {
        ans.at(j) = 1;
        ans.at(N - 1) = 1;
    }
    for(ll i = 0; i < N; i++) {
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}