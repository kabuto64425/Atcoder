#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

void swap(ll &a, ll &b) {
    ll temp = a;
    a = b;
    b = temp;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> P(N);
    for(ll &p : P) {
        cin >> p;
    }
    vector<ll> ans;
    ll target = 1;
    ll cur = 0;
    for(ll i = 1; i < N; i++) {
        if(P.at(i) == target) {
            for(ll j = i; j >= target; j--) {
                swap(P.at(j), P.at(j - 1));
                ans.push_back(j);
            }
            for(ll j = target - 1; j < i; j++) {
                if(P.at(j) != j + 1) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            target = i + 1;
        }
    }
    // targetがNでない→すべてのswapを使っていない
    if(target != N) {
        cout << -1 << endl;
        return 0;
    }
    for(const ll &elm : ans) {
        cout << elm << endl;
    }
    return 0;
}