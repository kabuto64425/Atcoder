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

    ll current = 0;
    ll plus = 0;

    for(ll i = 0; i < N; i++) {
        if(A.at(i) == 0) {
            current++;
        } else {
            current = max(current - 1, 0LL);
        }
        plus = max(plus, current);
    }

    current = 0;
    ll minus = 0;

    for(ll i = 0; i < N; i++) {
        if(A.at(i) == 1) {
            current--;
        } else {
            current = min(current + 1, 0LL);
        }
        minus = min(minus, current);
    }

    cout << plus - minus + 1 << endl;
    return 0;
}