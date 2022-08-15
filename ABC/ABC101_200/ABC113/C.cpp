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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> PY(M);
    for(pair<ll, ll> &py : PY) {
        cin >> py.first >> py.second;
    }
    vector<vector<ll>> v(N);
    for(const pair<ll, ll> &py : PY) {
        v.at(py.first - 1).push_back(py.second);
    }
    for(ll i = 0; i < N; i++) {
        sort(v.at(i).begin(), v.at(i).end());
        v.at(i).erase(unique(v.at(i).begin(), v.at(i).end()), v.at(i).end());
    }

    for(const pair<ll, ll> &py : PY) {
        const vector<ll> &ids = v.at(py.first - 1);
        ll id = lower_bound(ids.begin(), ids.end(), py.second) - ids.begin();
        id++;
        cout << setfill('0') << right << setw(6) << py.first << setfill('0') << right << setw(6) << id << endl;
    }
    return 0;
}