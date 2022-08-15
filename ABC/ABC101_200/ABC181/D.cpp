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
    vector<ll> bucket(10, 0);

    if(S.length() == 1) {
        if(S == "8") {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if(S.length() == 2) {
        ll num1 = (S.at(0) - '0') * 10 + (S.at(1) - '0');
        if(num1 % 8 == 0) {
            cout << "Yes" << endl;
            return 0;
        } else {
            ll num2 = (S.at(1) - '0') * 10 + (S.at(0) - '0');
            if(num2 % 8 == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }


    REP(i, S.length()) {
        ll index = (S.at(i) - '0');
        bucket.at(index)++;
    }

    for(ll i = 104; i <= 992; i += 8) {
        ll x = i;
        vector<ll> bucket2(10, 0);
        while(x != 0) {
            bucket2.at(x % 10)++;
            x /= 10;
        }
        bool flag = true;
        REP(j, 10) {
            if(bucket.at(j) < bucket2.at(j)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}