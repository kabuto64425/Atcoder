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

/**
 * ※10^6までであればEratosthenesの構造体を使用したほうが計算量が小さくなります！（EratosthenesStructという名前でスニペット登録済み）
 */
// nを素因数分解する
void primeFactorization(ll n, vector<pair<ll, ll>> &res) {
    res.clear();
    ll rem = n;
    for(ll i = 2; i * i <= n; i++) if(rem % i == 0) {
        ll exp = 0;
        while(rem % i == 0) {
            rem /= i;
            exp++;
        }
        res.emplace_back(i, exp);
    }
    if (rem != 1) {
        res.emplace_back(rem, 1);
    }
}

// nの約数の個数を求める
ll divisorsSize(ll n) {
    vector<pair<ll, ll>> primes;
    primeFactorization(n, primes);
    ll res = 1;
    for(pair<ll, ll> p : primes) {
        res *= (p.second + 1);
    }
    return res;
}

// nの約数を列挙したものをresに格納(昇順)
// resは処理の最初にclearで中身を消している。
// 約数の個数を求めるときはこの関数ではなく、divisorsSizeを使用する
// (divisorsSizeは約数を列挙せずに求めるため、実行時間がより小さい)
void divisors(ll n, vector<ll> &res) {
    res.clear();
    res.push_back(1);
    
    // n を素因数分解 (メンバ関数使用)
    vector<pair<ll, ll>> pf;
    primeFactorization(n, pf);
    
    // 約数列挙
    for (pair<ll, ll> p : pf) {
        ll s = (ll)res.size();
        for (ll i = 0; i < s; ++i) {
            ll v = 1;
            for (ll j = 0; j < p.second; ++j) {
                v *= p.first;
                res.push_back(res[i] * v);
            }
        }
    }
    sort(res.begin(), res.end());
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> res;
    primeFactorization(N, res);
    for(ll i = 0; i < res.size(); i++) {
        for(ll j = 0; j < res.at(i).second; j++) {
            cout << res.at(i).first << " ";
        }
    }
    cout << endl;
    return 0;
}