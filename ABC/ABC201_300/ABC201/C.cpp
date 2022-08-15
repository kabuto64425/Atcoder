#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll digsum(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(){
    string S;
    cin >> S;
    vector<bool> ok(10, false);
    vector<bool> ng(10, false);
    set<ll> both;
    for(ll i = 0; i < 10; i++) {
        if(S.at(i) == 'o') {
            ok.at(i) = true;
        }else if(S.at(i) == 'x') {
            ng.at(i) = true;
        } else {
            both.insert(i);
        }
    }

    ll ans = 0;


    for(ll i = 0; i <= 9999; i++) {
        vector<bool> nums(10, 0);
        if(i < 1000) {
            nums.at(0) = true;
        }
        ll n = i;
        while(n > 0) {
            nums.at(n % 10) = true;
            n /= 10;
        }
        bool flag = true;
        vector<bool> ok_copy = ok;
        for(ll j = 0; j < 10; j++) {
            if(nums.at(j)) {
                ok_copy.at(j) = false;
            }
        }
        for(ll j = 0; j < 10; j++) {
            if(ok_copy.at(j)) {
                flag = false;
            }
        }
        for(ll j = 0; j < 10; j++) {
            if(nums.at(j)) {
                if(ng.at(j)) {
                    flag = false;
                }
            }
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}