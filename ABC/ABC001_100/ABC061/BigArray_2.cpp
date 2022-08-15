#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> ab(N);
    for(pair<ll, ll> &elm : ab) {
        cin >> elm.first >> elm.second;
    }
    sort(ab.begin(), ab.end());
    ll current = 0;
    ll index = 0;
    while(current + ab.at(index).second < K) {
        current += ab.at(index).second;
        index++;
    }
    cout <<  ab.at(index).first << endl;
    return 0;
}