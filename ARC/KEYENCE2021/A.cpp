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
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    for(ll &elm : b) {
        cin >> elm;
    }
    vector<ll> amax(N, 0);
    amax.at(0) = a.at(0);
    for(ll i = 1; i < N; i++) {
        amax.at(i) = max(amax.at(i - 1), a.at(i));
    }

    ll currentMax = 0;

    for(ll i = 0; i < N; i++) {
        currentMax = max(currentMax, amax.at(i) * b.at(i));
        cout << currentMax << endl;
    }

    return 0;
}