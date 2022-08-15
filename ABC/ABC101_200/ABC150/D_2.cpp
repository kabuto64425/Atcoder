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

ll solver(ll N, ll M, const vector<ll> &a) {
    vector<ll> b = a;
    ll firstElm = b.at(0);
    ll l = firstElm;
    for(ll elm : b) {
        l = lcm(l, elm);
        if(l > (ll)1e12) {
            return 0;
        }
    }
    while(all_of(b.begin(), b.end(), [](ll elm) {return elm % 2 == 0;})) {
        for(ll &elm : b) {
            elm /= 2;
        }
    }
    for(ll elm : b) if(elm % 2 == 0) {
        return 0;
    }
    
    if(l / 2 > M) {
        return 0;
    }
    return (M - l / 2) / l + 1;
}

ll solver2(ll N, ll M, const vector<ll> &a) {
    ll ans = 0;
    for(ll i = 2; i <= M * 2; i += 2) {
        bool flag = all_of(ALL(a), [&i](ll x) {
            return ((i % x == 0) and ((i / x) % 2 == 1));
        });
        if(flag) {
            ans++;
        }
    }
    return ans;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    for(ll &elm : a) {
        cin >> elm;
    }
    
    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    while(true) {
        uniform_int_distribution<ll> dist_N(1, 3), dist_M(1, 100), dist_A(1, 10);
        ll N = dist_N(rnd);
        ll M = dist_M(rnd);
        vector<ll> a(N);
        for(ll i=0; i<N; i++) a[i] = dist_A(rnd) * 2;
        ll ans1 = solver(N, M, a);
        ll ans2 = solver2(N, M, a);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << M << endl;
            for(int i=0; i<N; i++) cout << a[i] << " \n"[i==N-1];
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/
    
    cout << solver(N, M, a) << endl;
    //cout << solver2(N, M, a) << endl;
    return 0;
}