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

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> v;
    char pre = S.at(0);
    ll count = 1;
    for(ll i = 1; i < N; i++) {
        if(pre == S.at(i)) {
            count++;
        } else {
            v.push_back(count);
            count = 1;
            pre = S.at(i);
        }
    }
    v.push_back(count);
    v.push_back(0);
    vector<ll> csum((ll)v.size() + 1, 0);
    for(ll i = 1; i <= (ll)v.size(); i++) {
        csum.at(i) = csum.at(i - 1) + v.at(i - 1);
    }
    ll ans = 0;
    for(ll i = 1; i < (ll)v.size(); i++) {
        ans += v.at(i) * csum.at(i);
    }
    cout << ans << endl;
    return 0;
}