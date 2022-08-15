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
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    set<ll> s;
    for(ll i = 0; i < N; i++) {
        s.insert(B.at(i));
    }
    ll hit = 0;
    ll blow = 0;
    for(ll i = 0; i < N; i++) {
        if(A.at(i) == B.at(i)) {
            hit++;
            continue;
        }
        if(s.count(A.at(i))) {
            blow++;
        }
    }
    cout << hit << endl;
    cout << blow << endl;
    return 0;
}