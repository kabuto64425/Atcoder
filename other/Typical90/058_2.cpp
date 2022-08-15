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

ll solver(ll N, ll K) {
    vector<vector<ll>> next(60, vector<ll>(100000));
    for (int v = 0; v < 100000; ++v) {
        next[0][v] = (v + digsum(v)) % 100000;
    }
    for (int d = 0; d + 1 < 60; ++d) {
        for (int v = 0; v < 100000; ++v) {
            next[d+1][v] = next[d][next[d][v]];
        }
    }
    ll v = N;
    for (int d = 0; d < 60; ++d) {
        if (K & (1LL<<d)) v = next[d][v];
    }
    return v;
}

ll solver2(ll N, ll K) {
    ll now = N;
    for(ll i = 0; i < K; i++) {
        now = (now + digsum(now)) % 100000;
    }
    return now;
}

int main(){
    ll N, K;
    cin >> N >> K;
    
    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());*/
    
    /*while(true) {
        uniform_int_distribution<ll> dist_N(1, 10), dist_K(1, 10000);
        ll N = dist_N(rnd);
        ll K = dist_K(rnd);
        ll ans1 = solver(N, K);
        ll ans2 = solver2(N, K);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << K << endl;
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/
    
    cout << solver(N, K) << endl;
    //cout << solver2(N, K) << endl;
    return 0;
}