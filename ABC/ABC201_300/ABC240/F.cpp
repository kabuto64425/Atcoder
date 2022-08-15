#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()
 
const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll solver(ll N, ll M, vector<ll> &x, vector<ll> &y) {
    vector<ll> b(N);
    vector<ll> c(N);
    b.at(0) = x.at(0) * y.at(0);
    for(ll i = 1; i < N; i++) {
        b.at(i) = b.at(i - 1) + x.at(i) * y.at(i);
    }
    c.at(0) = ((x.at(0) + b.at(0)) * y.at(0)) / 2;
    for(ll i = 1; i < N; i++) {
        c.at(i) = c.at(i - 1) + ((b.at(i - 1) + x.at(i) + b.at(i)) * y.at(i)) / 2;
    }
    ll ans = x.at(0);
    ans = max(ans, c.at(0));
    for(ll i = 1; i < N; i++) {
        ans = max(ans, c.at(i - 1) + b.at(i - 1) + x.at(i));
        ans = max(ans, c.at(i));
        if(b.at(i - 1) >= 0 and b.at(i) < 0) {
            // 極大値を探る
            ll count = b.at(i - 1) / abs(x.at(i));
            ll comp = c.at(i - 1) + (b.at(i - 1) + x.at(i) + b.at(i - 1) + x.at(i) * count) * count / 2;
            ans = max(ans, comp);
        }
    }
    return ans;
}

ll solver2(ll N, ll M, vector<ll> &x, vector<ll> &y) {
    vector<ll> a(M);
    ll cur = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = cur; j < cur + y.at(i); j++) {
            a.at(j) = x.at(i);
        }
        cur += y.at(i);
    }
    vector<ll> b(M), c(M);
    b.at(0) = a.at(0);
    c.at(0) = b.at(0);
    ll ans = c.at(0);
    for(ll i = 1; i < M; i++) {
        b.at(i) = b.at(i - 1) + a.at(i);
        c.at(i) = c.at(i - 1) + b.at(i);
        ans = max(ans, c.at(i));
    }
    return ans;
}

int main() {
    ll T;
    cin >> T;
    vector<ll> N(T), M(T);
    vector<vector<ll>> x(T), y(T);
    for(ll test = 0; test < T; test++) {
        cin >> N.at(test)>> M.at(test);
        for(ll i = 0; i < N.at(test); i++) {
            ll xi, yi;
            cin >> xi >> yi;
            x.at(test).push_back(xi);
            y.at(test).push_back(yi);
        }
    }

    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    /*for(ll test = 0; test < T; test++) {
        solver2(N.at(test), M.at(test), x.at(test), y.at(test));
    }*/

    /*while(true) {
        uniform_int_distribution<ll> dist_N(1, 3), dist_X(-4, 4);
        ll N = dist_N(rnd);
        uniform_int_distribution<ll> dist_M(N, 15);
        ll M = dist_M(rnd);
        vector<ll> x(N), y(N);
        vector<ll> z(N + 1);
        z.at(0) = 0;
        z.at(N) = M - N;
        uniform_int_distribution<ll> dist_Z(0, M - N);
        for(ll i = 1; i < N - 1; i++) {
            z.at(i) = dist_M(rnd);
        }
        sort(ALL(z));
        for(ll i = 0; i < N; i++) {
            x.at(i) = dist_X(rnd);
            y.at(i) = z.at(i + 1) - z.at(i) + 1;
        }
        ll ans1 = solver(N, M, x, y);
        ll ans2 = solver2(N, M, x, y);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << M << endl;
            for(int i=0; i<N; i++) cout << x[i] << " " << y[i]<< " \n"[i==N-1];
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/
    
    for(ll test = 0; test < T; test++) {
        ll ans1 = solver(N.at(test), M.at(test), x.at(test), y.at(test));
        cout << ans1 << endl;
    }
    return 0;
}
