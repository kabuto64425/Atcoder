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
    vector<ll> A(N), B(N), C(N);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    for(ll &c : C) {
        cin >> c;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    ll ia = 0;
    ll ib = 0;
    ll ic = 0;
    ll ans = 0;
    while(ia < N and ib < N and ic < N) {
        ll a = A.at(ia);
        while(ib < N and a >= B.at(ib)) {
            ib++;
        }
        if(ib >= N) {
            break;
        }
        ll b = B.at(ib);
        while(ic < N and b >= C.at(ic)) {
            ic++;
        }
        if(ic >= N) {
            break;
        }
        ll c = C.at(ic);
        ans++;
        ia++;
        ib++;
        ic++;
    }
    cout << ans << endl;
    return 0;
}