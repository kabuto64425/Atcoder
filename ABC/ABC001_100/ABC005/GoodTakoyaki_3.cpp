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
    ll T;
    ll N;
    cin >> T >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll M;
    cin >> M;
    vector<ll> B(M);
    for(ll &b : B) {
        cin >> b;
    }
    queue<ll> queA;
    queue<ll> queB;
    for(const ll &a : A) {
        queA.push(a);
    }
    for(const ll &b : B) {
        queB.push(b);
    }
    while(!queA.empty()) {
        ll a = queA.front();
        queA.pop();
        ll b = queB.front();
        if(a <= b and b <= a + T) {
            queB.pop();
            if(queB.empty()) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}