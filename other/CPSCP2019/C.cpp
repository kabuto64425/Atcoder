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

void dfs(const ll N, const ll K, const vector<ll> &A, vector<ll> &vec, ll current, ll &ans) {
    if(vec.size() == K) {
        ll sum = 0;
        for(ll i = 0; i < K; i++) {
            sum += A.at(vec.at(i));
        }
        ll count = 0;
        for(ll i = 0; i < 10; i++) {
            count += sum % 5;
            sum -= sum % 5;
            count += (sum % 10) / 5;
            sum /= 10;
        }
        ans = min(ans, count);
        return;
    }
    for(ll i = current + 1; i < N; i++) {
        vec.push_back(i);
        dfs(N, K, A, vec, i, ans);
        vec.pop_back();
    }
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<ll> vec;
    ll ans = INF;
    dfs(N, K, A, vec, -1, ans);
    cout << ans << endl;
    return 0;
}