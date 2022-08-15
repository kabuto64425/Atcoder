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

bool solve(ll K, ll N, ll M, ll mid, const vector<ll> &A, vector<ll> &B) {
    ll sumMin = 0;
    ll sumMax = 0;
    vector<ll> mins(K);
    vector<ll> maxs(K);
    for(ll i = 0; i < K; i++) {
        ll under = max(A.at(i) * M - mid, 0LL);
        ll upper = min(A.at(i) * M + mid, N * M);
        sumMin += (under + N - 1) / N;
        sumMax += upper / N;
        mins.at(i) = (under + N - 1) / N;
        maxs.at(i) = upper / N;
    }

    if(M >= sumMin and M <= sumMax) {
        ll target = M;
        for(ll i = 0; i < K; i++) {
            B.at(i) = mins.at(i);
            target -= mins.at(i);
        }
        for(ll i = 0; i < K and target != 0; i++) {
            ll add = min(maxs.at(i) - mins.at(i), target);
            B.at(i) += add;
            target -= add;
        }
        return true;
    }

    return false;
}

int main(){
    ll K, N, M;
    cin >> K >> N >> M;
    vector<ll> A(K);
    for(ll &a : A) {
        cin >> a;
    }

    vector<ll> B(K);

    ll ok = N * M;
    ll ng = -1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(solve(K, N, M, mid, A, B)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    for(const ll &b : B) {
        cout << b << " ";
    }

    cout << endl;

    return 0;
}