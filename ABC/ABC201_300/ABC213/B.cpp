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

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i).first;
        A.at(i).second = i + 1;
    }
    sort(A.begin(), A.end());
    cout << A.at(N - 2).second << endl;
    return 0;
}