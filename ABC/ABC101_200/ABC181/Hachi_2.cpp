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
    string S;
    cin >> S;
    if(S.length() <= 2) {
        ll num1 = stoi(S);
        reverse(S.begin(), S.end());
        ll num2 = stoi(S);
        if(num1 % 8 == 0 or num2 % 8 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    
    vector<ll> bucket(10, 0);
    for(const char &c : S) {
        bucket.at(c - '0')++;
    }

    for(ll i = 104; i < 1000; i += 8) {
        vector<ll> need(10, 0);
        ll x = i;
        while(x > 0) {
            need.at(x % 10)++;
            x /= 10;
        }
        bool flag = true;
        for(ll j = 0; j < 10; j++) {
            if(bucket.at(j) < need.at(j)) {
                flag = false;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}