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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll ans = 0;
    bool flag = false;
    FOR(i, 0, N - 2) {
        if(flag) {
            ans += A.at(i);
            flag = false;
            continue;
        }
        if(A.at(i) >= 0 && A.at(i + 1) >= 0) {
            flag = true;
        }

        if(A.at(i) <= 0 && A.at(i + 1) <= 0) {
            flag = true;
            A.at(i) = -A.at(i);
            A.at(i + 1) = -A.at(i + 1);
        }

        if(A.at(i) + A.at(i + 1) < 0) {
            A.at(i) = -A.at(i);
            A.at(i + 1) = -A.at(i + 1);
        }
        ans += A.at(i);
    }
    ans += A.at(N - 1);
    cout << ans << endl;
    return 0;
}