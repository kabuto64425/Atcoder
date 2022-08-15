#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

mint solver(ll N, ll D) {
    mint ans = 0;
    for(ll d = 0; d < N; d++) {
        mint current = 0;
        ll length = 2 * (N - d - 1) + 1;
        if(d + D <= N - 1) {
            current += ((mint)2).pow(D);
            current += ((mint)2).pow(D);
            if(D >= 2) {
                current += ((mint)2).pow(D - 2) * ((mint)(D - 1));
                current += ((mint)2).pow(D - 2) * ((mint)(D - 1));
            }
        } else if(D < length and D >= 2) {
            current += ((mint)2).pow(D - 2) * ((mint)(length - D));
            current += ((mint)2).pow(D - 2) * ((mint)(length - D));
        }
        current *= ((mint)2).pow(d);
        ans += current;
    }
    return ans;
}

int main(){
    ll N, D;
    cin >> N >> D;

    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    while(true) {
        uniform_int_distribution<ll> dist_N(1, 100), dist_D(1, 1000);
        ll N = dist_N(rnd);
        ll D = dist_D(rnd);
        mint ans1 = solver(N, D);
    }*/
    
    cout << solver(N, D).val() << endl;
    return 0;
}