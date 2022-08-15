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

ll solver(ll N, ll M, const vector<ll> &A) {
    vector<ll> vec(N);
    for(ll i = 0; i < M; i++) {
        vec.at(A.at(i))++;
    }
    ll ans = N;
    for(ll i = 0; i < N; i++) {
        if(vec.at(i) == 0) {
            ans = i;
            break;
        }
    }
    for(ll i = M; i < N; i++) {
        ll x = A.at(i - M);
        ll y = A.at(i);
        vec.at(x)--;
        vec.at(y)++;
        if(vec.at(x) == 0) {
            ans = min(ans, x);
        }
    }
    return ans;
}

ll solver2(ll N, ll M, const vector<ll> &A) {
    ll ans = INF;
    for(ll i = 0; i < N - M + 1; i++) {
        vector<ll> vec(N);
        for(ll j = 0; j < M; j++) {
            vec.at(A.at(i + j))++;
        }
        for(ll i = 0; i < N; i++) {
            if(vec.at(i) == 0) {
                ans = min(ans, i);
                break;
            }
        }
    }
    return ans;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }

    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    while(true) {
        uniform_int_distribution<ll> dist_N(1, 5);
        ll N = dist_N(rnd);
        uniform_int_distribution<ll> dist_M(1, N);
        ll M = dist_M(rnd);
        vector<ll> a(N);
        uniform_int_distribution<ll> dist_A(0, N - 1);
        for(ll i=0; i<N; i++) a[i] = dist_A(rnd);
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


    cout << solver(N, M, A) << endl;
    //cout << solver2(N, M, A) << endl;
    return 0;
}