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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> a[i];
    }
    vector<ll> ruiseki(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        ruiseki[i] = ruiseki[i - 1] + a[i];
    }
    ll ans = 0;
    ll right = 0;
    ll left = 0;
    while(left <= N) {
        while(right <= N and ruiseki[right] - ruiseki[left] < K) {
            right++;
        }
        if(right > N) {
            break;
        }
        ans += (N - right + 1);
        left++;
    }
    cout << ans << endl;
    return 0;
}