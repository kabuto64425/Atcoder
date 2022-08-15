#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll pow_selfmade(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x;
        x = (x)*(x);
        n >>= 1;
    }
    return res;
}

ll culcscore(const string &cards, ll a) {
    vector<ll> bucket(10, 0);
    for(ll i = 0; i < 4; i++) {
        ll x = (ll)(cards.at(i) - '0');
        bucket.at(x)++;
    }
    bucket.at(a)++;
    ll res = 0;

    for(ll i = 1; i <= 9; i++) {
        res += i * pow_selfmade(10, bucket.at(i));
    }
    return res;
}

int main(){
    ll K;
    cin >> K;
    string S;
    string T;
    cin >> S >> T;
    long double ans = 0;
    for(ll i = 1; i <= 9; i++) for(ll j = 1; j <= 9; j++) {
        ll tscore = culcscore(S, i);
        ll ascore = culcscore(T, j);
        vector<ll> bucket(10, K);
        bucket.at(0) = 0;
        for(ll k = 0; k < 4; k++) {
            ll x = (ll)(S.at(k) - '0');
            bucket.at(x)--;
        }
        for(ll k = 0; k < 4; k++) {
            ll x = (ll)(T.at(k) - '0');
            bucket.at(x)--;
        }
        long double p = 0;
        if(tscore > ascore) {
            ll rest = 9 * K - 8;
            ll a = bucket.at(i);
            bucket.at(i)--;

            p = (a / (long double) rest);

            rest--;
            ll b = bucket.at(j);

            p *= (b / (long double) rest);

            bucket.at(j)--;
            rest--;
            if(a <= 0 or b <= 0) {
                continue;
            }
            ans += p;
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}