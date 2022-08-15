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

ll solver(ll N, ll X, ll Y, vector<ll> &A, vector<ll> &B) {
    
    vector<vector<vector<ll>>> dp(301, vector<vector<ll>>(301, vector<ll>(301, INF)));
    dp.at(0).at(0).at(0) = 0;
    for(ll i = 0; i <= N - 1; i++) {
        for(ll a = 0; a <= 300; a++) {
            for(ll b = 0; b <= 300; b++) {
                dp.at(i + 1).at(a).at(b) = min(dp.at(i + 1).at(a).at(b), dp.at(i).at(a).at(b));
                dp.at(i + 1).at(min(a + A.at(i), 300LL)).at(min(b + B.at(i), 300LL)) = min(dp.at(i + 1).at(min(a + A.at(i), 300LL)).at(min(b + B.at(i), 300LL)), dp.at(i).at(a).at(b) + 1);
            }
        }
    }
    /*for(ll i = 1; i <= N; i++) {
        for(ll a = 0; a <= 300; a++) {
            for(ll b = 0; b <= 300; b++) {
                dp.at(i).at(a).at(b) = min(dp.at(i).at(a).at(b), dp.at(i - 1).at(a).at(b));
                if(a - A.at(i - 1) >= 0 and b - B.at(i - 1) >= 0) {
                    dp.at(i).at(a).at(b) = min(dp.at(i).at(a).at(b), dp.at(i - 1).at(a - A.at(i - 1)).at(b - B.at(i - 1)) + 1);
                }
            }
        }
    }*/
    ll ans = INF;
    for(ll a = 0; a <= 300; a++) {
        for(ll b = 0; b <= 300; b++) {
            if(a < X or b < Y) {
                continue;
            }
            ans = min(ans, dp.at(N).at(a).at(b));
        }
    }
    if(ans == INF) {
        return -1;
    }
    return ans;
}

ll solver2(ll N, ll X, ll Y, vector<ll> &A, vector<ll> &B) {
    ll ans = INF;
    for(ll bit = 0; bit < (1 << N); bit++) {
        ll x = 0;
        ll y = 0;
        ll count = 0;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                x += A.at(i);
                y += B.at(i);
                count++;
            }
        }
        if(x >= X and y >= Y) {
            ans = min(ans, count);
        }
    }
    if(ans == INF) {
        return -1;
    }
    return ans;
}

int main(){
    ll N;
    cin >> N;
    ll X, Y;
    cin >> X >> Y;
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    /*andom_device seed_gen;
    mt19937_64 rnd(seed_gen());

     while(true) {
        uniform_int_distribution<ll> dist_N(1, 3), dist_X(1, 200), dist_Y(1, 200), dist_A(1, 200), dist_B(1, 200);
        ll N = dist_N(rnd);
        ll X = dist_X(rnd);
        ll Y = dist_Y(rnd);
        vector<ll> A(N), B(N);
        for(ll i = 0; i < N; i++) {
            A.at(i) = dist_A(rnd);
            B.at(i) = dist_B(rnd);
        }
        ll ans1 = solver(N, X, Y, A, B);
        ll ans2 = solver2(N, X, Y, A, B);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << X << " " << Y << endl;
            for(int i=0; i<N; i++) cout << A[i] << " \n"[i==N-1];
            for(int i=0; i<N; i++) cout << B[i] << " \n"[i==N-1];
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
     }*/

    cout << solver(N, X, Y, A, B) << endl;
    //cout << solver2(N, X, Y, A, B) << endl;
    return 0;
}