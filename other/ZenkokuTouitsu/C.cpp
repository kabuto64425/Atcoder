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
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    vector<tuple<ll, ll, ll>> v(N);
    for(ll i = 0; i < N; i++) {
        v.at(i) = {-(A.at(i) + B.at(i)), A.at(i), B.at(i)};
    }
    sort(ALL(v));
    ll pa = 0, pb = 0;
    for(ll i = 0; i < N; i++) {
        if(i % 2 == 0) {
            pa += get<1>(v.at(i));
        } else {
            pb += get<2>(v.at(i));
        }
    }
    cout << pa - pb << endl;
    return 0;
}