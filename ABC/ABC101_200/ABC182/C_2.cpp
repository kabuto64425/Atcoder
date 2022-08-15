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

signed main(){
    ll N;
    cin >> N;

    ll target = digsum(N);

    vector<ll> digDiv3(3, 0);

    ll digit = 0;
    while(N > 0) {
        digDiv3.at((N % 10) % 3)++;
        digit++;
        N /= 10;
    }
    if(target % 3 == 0) {
        cout << 0 << endl;
        return 0;
    } else if(target % 3 == 1) {
        if(digDiv3.at(1) >= 1 && digit >= 2) {
            cout << 1 << endl;
            return 0;
        }
        if(digDiv3.at(2) >= 2 && digit >= 3) {
            cout << 2 << endl;
            return 0;
        }
    } else if(target % 3 == 2) {
        if(digDiv3.at(2) >= 1 && digit >= 2) {
            cout << 1 << endl;
            return 0;
        }
        if(digDiv3.at(1) >= 2 && digit >= 3) {
            cout << 2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}