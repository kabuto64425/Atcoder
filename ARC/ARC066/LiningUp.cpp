#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    vector<ll> bucket(N, 0);
    for(const ll &a : A) {
        bucket.at(a)++;
    }
    if(N % 2 == 0) {
        mint ans = 1;
        for(ll i = 1; i <= N - 1; i++) {
            if(i % 2 == 0) {
                if(bucket.at(i) > 0) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                if(bucket.at(i) != 2) {
                    cout << 0 << endl;
                    return 0;
                }
                ans *= 2;
            }
        }
        cout << ans.val() << endl;
    } else {
        if(bucket.at(0) != 1) {
            cout << 0 << endl;
            return 0;
        }
        mint ans = 1;
        for(ll i = 1; i <= N - 1; i++) {
            if(i % 2 == 0) {
                if(bucket.at(i) != 2) {
                    cout << 0 << endl;
                    return 0;
                }
                ans *= 2;
            } else {
                if(bucket.at(i) > 0) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        cout << ans.val() << endl;
    }

    return 0;
}