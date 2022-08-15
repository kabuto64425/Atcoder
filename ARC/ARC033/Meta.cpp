#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll Na, Nb;
    cin >> Na >> Nb;
    vector<ll> A(Na);
    vector<ll> B(Nb);
    for(ll &a : A) {
        cin >> a;
    }
    for(ll &b : B) {
        cin >> b;
    }
    vector<bool> vec(1000000001, false);
    ll count = 0;
    for(const ll &a : A) {
        vec.at(a) = true;
    }
    for(const ll &b : B) {
        if(vec.at(b)) {
            count++;
        }
    }
    cout << fixed << setprecision(20) << count / (long double)(Na + Nb - count) << endl;
    return 0;
}