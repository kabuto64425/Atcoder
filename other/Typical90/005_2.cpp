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

vector<vector<mint>> matrixMultiplication(vector<vector<mint>> matrixA, vector<vector<mint>> matrixB) {
    ll l = matrixA.size();
    ll m = matrixB.at(0).size();
    ll n = matrixB.size();
    vector<vector<mint>> ret(l, vector<mint>(m, 0));
    for(ll i = 0; i < l; i++) {
        for(ll j = 0; j < m; j++) {
            for(ll k = 0; k < n; k++) {
                ret.at(i).at(j) += matrixA.at(i).at(k) * matrixB.at(k).at(j);
            }
        }
    }
    return ret;
}

vector<vector<mint>> matrixPower(vector<vector<mint>> matrix, ll n) {
    ll m = matrix.size();
    vector<vector<mint>> ret(m, vector<mint>(m, 0));
    for(ll i = 0; i < m; i++) {
        ret.at(i).at(i) = 1;
    }
    while(n > 0) {
        if(n & 1) {
            ret = matrixMultiplication(matrix, ret);
        }
        matrix = matrixMultiplication(matrix, matrix);
        n >>= 1;
    }
    return ret;
}

int main(){
    ll N, B, K;
    cin >> N >> B >> K;
    vector<ll> c(K);
    for(ll &elm : c) {
        cin >> elm;
    }

    vector<vector<mint>> matrix(B, vector<mint>(B, 0));
    for(ll j = 0; j < B; j++) {
        for(ll k = 0; k < K; k++) {
            ll mod = (j * 10 + c.at(k)) % B;
            matrix.at(j).at(mod)++;
        }
    }

    vector<vector<mint>> dp(B, vector<mint>(1, 0));
    dp.at(0).at(0) = 1;

    dp = matrixMultiplication(matrixPower(matrix, N), dp);
    cout << dp.at(0).at(0).val() << endl;
    return 0;
}