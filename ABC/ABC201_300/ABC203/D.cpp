#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

bool solve(const ll mid, const ll N, const ll K, const vector<vector<ll>> &A) {
    vector<vector<ll>> counts(N + 1, vector<ll>(N + 1, 0));
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            if(A.at(i).at(j) <= mid) {
                counts.at(i).at(j) = 1;
            }
        }
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            counts.at(i).at(j) += counts.at(i).at(j - 1);
        }
    }
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            counts.at(j).at(i) += counts.at(j - 1).at(i);
        }
    }
    ll border = K * K - ((K * K) / 2 + 1);
    for(ll i = K; i <= N; i++) {
        for(ll j = K; j <= N; j++) {
            ll count = counts.at(i).at(j) - counts.at(i - K).at(j) - counts.at(i).at(j - K) + counts.at(i - K).at(j - K);
            if(count < border) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> A(N + 1, vector<ll>(N + 1));
    vector<ll> vec;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= N; j++) {
            cin >> A.at(i).at(j);
            vec.push_back(A.at(i).at(j));
        }
    }

    if(N == K) {
        sort(vec.begin(), vec.end(), greater<ll>());
        cout << vec.at((N * N) / 2) << endl;
        return 0;
    }

    ll ok = 1000000000;
    ll ng = -1;

    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(mid, N, K, A)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}