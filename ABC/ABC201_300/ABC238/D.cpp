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

void solver(ll a, ll s) {
    bitset<60> bs(a);
    if(s - a * 2 < 0) {
        cout << "No" << endl;
        return;
    }

    ll x = s - a * 2;
    bitset<60> bsx(x);
    for(ll i = 0; i < 60; i++) {
        if(bs.test(i) and bsx.test(i)) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main(){
    ll T;
    cin >> T;
    vector<ll> a(T), s(T);
    for(ll i = 0; i < T; i++) {
        cin >> a.at(i) >> s.at(i);
    }
    for(ll i = 0; i < T; i++) {
        solver(a.at(i), s.at(i));
    }
    return 0;
}