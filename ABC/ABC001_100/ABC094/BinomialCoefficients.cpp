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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &elm : a) {
        cin >> elm;
    }
    sort(a.begin(), a.end());
    ll first = a[n -1];
    ll target = (first + 1) / 2;
    ll index = lower_bound(a.begin(), a.end(), target) - a.begin();
    ll second;
    if(index == 0) {
        second = a[0];
    } else if(index >= n) {
        second = a[n - 1];
    } else {
        if(abs(target - a[index]) < abs(target - a[index - 1])) {
            second = a[index];
        } else {
            second = a[index - 1];
        }
    }
    cout << first << " " << second << endl;
    return 0;
}