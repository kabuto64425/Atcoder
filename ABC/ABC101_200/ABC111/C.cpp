#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &elm : v) {
        cin >> elm;
    }
    vector<pair<ll, ll>> countA(110000);
    vector<pair<ll, ll>> countB(110000);
    for(ll i = 0; i < 110000; i++) {
        countA[i].first = i;
        countB[i].first = i;
    }
    for(ll i = 0; i < n; i++) {
        if(i % 2 == 0) {
            countA[v[i]].second++;
        } else {
            countB[v[i]].second++;
        }
    }
    auto comp = [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second > b.second;
    };
    sort(countA.begin(), countA.end(), comp);
    sort(countB.begin(), countB.end(), comp);
    if(countA[0].first != countB[0].first) {
        cout << (n - countA[0].second - countB[0].second) << endl;
    } else {
        ll ans = max(countA[1].second + countB[0].second, countA[0].second + countB[1].second);
        cout << n - ans << endl;
    }
    return 0;
}