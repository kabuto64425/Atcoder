#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll ans = 0;
    ll current = 0;
    FOR(i, 2, 1000) {
        ll count = 0;
        for(const ll &a : A) {
            if(a % i == 0) {
                count++;
            }
        }
        if(count > current) {
            ans = i;
            current = count;
        }
    }
    cout << ans << endl;
    //小数の桁数の出力指定
    //cout << fixed << setprecision(20) << endl;
    return 0;
}