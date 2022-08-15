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

ll solver(const ll &N, ll &K, ll &P, vector<ll> &A) {
    vector<ll> B;
    ll half = (N + 1) / 2;
    for(ll i = 0; i < half; i++) {
        B.push_back(A.at(i));
    }
    vector<ll> C;
    for(ll i = half; i < N; i++) {
        C.push_back(A.at(i));
    }

    vector<vector<ll>> listsB(41);
    for(ll bit = 0; bit < (1 << half); bit++) {
        ll count = 0;
        ll sum = 0;
        for(ll i = 0; i < half; i++) {
            if(bit & (1 << i)) {
                count++;
                sum += B.at(i);
            }
        }
        listsB.at(count).push_back(sum);
    }

    vector<vector<ll>> listsC(41);
    ll rest = N - half;
    for(ll bit = 0; bit < (1 << rest); bit++) {
        ll count = 0;
        ll sum = 0;
        for(ll i = 0; i < rest; i++) {
            if(bit & (1 << i)) {
                count++;
                sum += C.at(i);
            }
        }
        listsC.at(count).push_back(sum);
    }
    for(ll i = 0; i <= 40; i++) {
        sort(ALL(listsC.at(i)));
    }
    ll ans = 0;
    for(ll i = 0; i <= 40; i++) {
        ll j = K - i;
        if(j < 0) {
            break;
        }
        for(ll &priceB : listsB.at(i)) {
            vector<ll> &listC = listsC.at(j);
            ll partial = upper_bound(listC.begin(), listC.end(), P - priceB) - listC.begin();
            ans += partial;
        }
    }
    return ans;
}

ll solver2(const ll &N, ll &K, ll &P, vector<ll> &A) {
    ll ans = 0;
    for(ll bit = 0; bit < (1 << N); bit++) {
        ll count = 0;
        ll sum = 0;
        for(ll i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                count++;
                sum += A.at(i);
            }
        }
        if(count == K and sum <= P) {
            ans++;
        }
    }
    return ans;
}

int main(){
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }

    //std::random_device seed_gen;
    //std::mt19937_64 engine(seed_gen());

    /*while(true) {
        ll N = engine() % 21 + 1;
        ll K = engine() % N + 1;
        ll P = engine() % (long long)1e18 + 1;
        vector<ll> A(N);
        for(ll &a : A) {
            a = engine() % (long long)1e16 + 1;
        }
        ll ans1 = solver(N, K, P, A);
        ll ans2 = solver(N, K, P, A);
        if(ans1 != ans2) {
            cout << ans1 << " " << ans2 << endl;
            cout << N << " " << K << " " << P << endl;
            for(ll &a : A) {
                cout << a << " ";
            }
            cout << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/
    
    cout << solver(N, K, P, A) << endl;
    //cout << solver2(N, K, P, A) << endl;
    return 0;
}