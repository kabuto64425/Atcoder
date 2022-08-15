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

long long modpow(long long a, long long b, long long m) {
    long long p = 1, q = a;
    for (int i = 0; i < 63; i++) {
        if ((b & (1LL << i)) != 0) {
            p *= q;
            p %= m;
        }
        q *= q;
        q %= m;
    }
    return p;
}


int main(){
    ll N, B, K;
    cin >> N >> B >> K;
    vector<ll> c(K);
    for(ll &elm : c) {
        cin >> elm;
    }

    vector<ll> power10(64);
    for (int i = 0; i <= 62; i++) {
        power10.at(i) = modpow(10LL, (1LL << i), B);
    }

    vector<vector<mint>> DP(64, vector<mint>(1009, 0));
    for(ll i = 0; i < K; i++) {
        DP.at(0).at(c.at(i) % B)++;
    }

    for(ll i = 0; i < 62; i++) {
        for(ll j = 0; j < B; j++) {
            for(ll k = 0; k < B; k++) {
                ll nex = (power10.at(i) * j + k) % B;
                DP.at(i + 1).at(nex) += DP.at(i).at(j) * DP.at(i).at(k);
            }
        }
    }

    vector<vector<mint>> answer(64, vector<mint>(1009, 0));
    answer.at(0).at(0) = 1;
    for (ll i = 0; i < 62; i++) {
        if ((N & (1LL << i)) != 0LL) {
            for (ll j = 0; j < B; j++) {
                for (ll k = 0; k < B; k++) {
                    ll nex = (j * power10[i] + k) % B;
                    answer.at(i + 1).at(nex) += answer.at(i).at(j) * DP.at(i).at(k);
                }
            }
        } else {
            for (int j = 0; j < B; j++) {
                answer.at(i + 1).at(j) = answer.at(i).at(j);
            }
        }
    }

    cout << answer.at(62).at(0).val() << endl;

    return 0;
}