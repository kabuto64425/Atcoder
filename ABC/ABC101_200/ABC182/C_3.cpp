#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

ll digsum(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    ll sum = digsum(N);
    vector<ll> vec(3, 0);
    ll digSize = 0;
    while(N > 0) {
        vec.at((N % 10) % 3)++;
        digSize++;
        N /= 10;
    }

    if(sum % 3 == 0) {
        cout << 0 << endl;
    } else if(sum % 3 == 1) {
        if(vec.at(1) >= 1 && digSize >= 2) {
            cout << 1 << endl;
        } else if(vec.at(2) >= 2 && digSize >= 3) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if(sum % 3 == 2) {
        if(vec.at(2) >= 1 && digSize >= 2) {
            cout << 1 << endl;
        } else if(vec.at(1) >= 2 && digSize >= 3) {
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}