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
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(ALL(A));
    vector<ll> count(1100000);
    vector<bool> hurui(1100000, true);


    for(ll i = 0; i < N; i++) {
        count.at(A.at(i))++;
        if(!hurui.at(A.at(i)) or count.at(A.at(i)) >= 2) {
            continue;
        }
        for(ll j = 2; A.at(i) * j <= 1000000; j++) {
            hurui.at(A.at(i) * j) = false;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        if(count.at(A.at(i)) == 1 and hurui.at(A.at(i))) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}