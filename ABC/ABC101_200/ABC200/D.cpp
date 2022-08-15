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
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
    }
    ll num = min(8LL, N);
    vector<vector<ll>> vec(200);
    for(ll bit = 0; bit < (1 << num); bit++) {
        if(bit == 0) {
            continue;
        }
        ll sum = 0;
        vector<ll> v;
        for(ll i = 0; i < num; i++) {
            if(bit & (1 << i)) {
                sum = (sum + A.at(i) % 200) % 200;
                v.push_back(i + 1);
            }
        }
        if(vec.at(sum).empty()) {
            vec.at(sum) = v;
        } else {
            cout << "Yes" << endl;
            cout << vec.at(sum).size() << " ";
            for(const ll &elm : vec.at(sum)) {
                cout << elm << " ";
            }
            cout << endl;
            cout << v.size() << " ";
            for(const ll &elm : v) {
                cout << elm << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}