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
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> B(N);
    for(ll &b : B) {
        cin >> b;
    }

    sort(B.begin(), B.end());

    set<ll> s;

    do {
        ll x = (A.at(0) ^ B.at(0));
        bool flag = true;
        for(ll i = 1; i < N; i++) {
            if(x != (A.at(i) ^ B.at(i))) {
                flag = false;
                break;
            }
        }
        if(flag) {
            s.insert(x);
        }
    } while (next_permutation(B.begin(), B.end()));
    cout << s.size() << endl;
    for(ll x : s) {
        cout << x << endl;
    }
    return 0;
}