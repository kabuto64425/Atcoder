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

ll colorNum(char c) {
    if(c == 'R') {
        return 0;
    }
    if(c == 'G') {
        return 1;
    }
    return 2;
}

int main(){
    ll N;
    cin >> N;
    string S;
    string T;
    cin >> S;
    cin >> T;
    vector<vector<ll>> v(N, vector<ll>(N));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            ll s = colorNum(S.at(i));
            ll t = colorNum(T.at(j));
            v.at(i).at(j) = (3 - (s + t) % 3) % 3;
        }
    }
    ll ans = 0;
    for(ll k = -(N - 1); k <= (N - 1); k++) {
        ll first = v.at(-min(k, 0LL)).at(max(k, 0LL));
        bool flag = true;
        for(ll i = 1; i < N - abs(k); i++) {
            if(v.at(i - min(k, 0LL)).at(i + max(k, 0LL)) != first) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}