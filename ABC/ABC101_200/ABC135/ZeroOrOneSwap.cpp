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

bool isAsc(vector<ll> vec) {
    for(ll i = 0; i <= vec.size() - 2; i++) {
        if(vec.at(i) > vec.at(i + 1)) {
            return false;
        }
    }
    return true;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> p(N);
    for(ll &elm : p) {
        cin >> elm;
    }

    if(isAsc(p)) {
        cout << "YES" << endl;
        return 0;
    }
    
    for(ll i = 0; i <= N - 2; i++) {
        for(ll j = i + 1; j <= N -1; j++) {
            vector<ll> q = p;
            swap(q.at(i), q.at(j));
            if(isAsc(q)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}