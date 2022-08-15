#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

ll solver(ll N, vector<ll> &A) {
    vector<ll> sum(N + 1);
    ll ans = 0;
    ll x = 0;
    ll right = -100000001;
    FOR(i, 1, N) {
        sum.at(i) = sum.at(i - 1) + A.at(i - 1);
        right = max(right, sum.at(i));
        ans = max(ans, x + right);
        x += sum.at(i);
    }
    return ans;
}

ll solver2(ll N, vector<ll> &A) {
    ll ans = 0;
    ll x = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < i + 1; j++) {
            x += A.at(j);
            ans = max(ans, x);
        }
    }
    return ans;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A.at(i);
    }

    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    while(true) {
        uniform_int_distribution<ll> dist_N(1, 10), dist_A(-100, 100);
        ll N = dist_N(rnd);
        vector<ll> A(N);
        for(ll i=0; i<N; i++) A[i] = dist_A(rnd);
        ll ans1 = solver(N, A);
        ll ans2 = solver2(N, A);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << endl;
            for(int i=0; i<N; i++) cout << A[i] << " \n"[i==N-1];
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        }
    }*/

    cout << solver(N, A) << endl;
    //cout << solver2(N, A) << endl;
    
    return 0;
}