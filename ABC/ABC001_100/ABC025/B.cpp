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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<string> s(N);
    vector<ll> d(N);
    for(ll i = 0; i < N; i++) {
        cin >> s.at(i) >> d.at(i);
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        ll x;
        if(d.at(i) < A) {
            x = A;
        } else if(d.at(i) > B) {
            x = B;
        } else {
            x = d.at(i);
        }
        if(s.at(i) == "West") {
            ans -= x;
        } else {
            ans += x;
        }
    }
    if(ans < 0) {
        cout << "West " << abs(ans) << endl;
    } else if(ans > 0) {
        cout << "East " << abs(ans) << endl;
    }else {
        cout << abs(ans) << endl;
    }
    return 0;
}