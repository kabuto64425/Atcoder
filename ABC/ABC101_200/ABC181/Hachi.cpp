#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    string S;
    cin >> S;
    if(S.length() == 1) {
        if(S.at(0) == '8') {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if(S.length() == 2) {
        ll x = S.at(0) - '0';
        ll y = S.at(1) - '0';
        if((x * 10 + y) % 8 == 0 || (y * 10 + x) % 8 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    vector<ll> vec(10, 0);

    REP(i, S.length()) {
        vec.at(S.at(i) - '0')++;
    }

    for(ll i = 104; i <= 992; i += 8) {
        vector<ll> vec_copy = vec;
        vec_copy.at(i / 100)--;
        vec_copy.at((i % 100) / 10)--;
        vec_copy.at((i % 100) % 10)--;

        if(all_of(vec_copy.begin(), vec_copy.end(), [](ll x) { return x >= 0;})) {
            cout << "Yes" << endl;
            return 0; 
        }
    }
    cout << "No" << endl;
}