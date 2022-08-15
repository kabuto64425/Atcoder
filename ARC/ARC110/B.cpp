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
    ll N;
    cin >> N;
    string T;
    cin >> T;
    string partial = "110";
    bool finded = false;
    for(ll i = 0; i < 3; i++) {
        bool flag = true;
        for(ll j = 0; j < N; j++) {
            if(T.at(j) != partial.at((i + j) % 3)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            finded = true;
        }
    }
    if(!finded) {
        cout << 0 << endl;
        return 0;
    }
    if(T == "1") {
        cout << 10000000000 * 2 << endl;
        return 0;
    }
    if(T == "11") {
        cout << 10000000000 << endl;
        return 0;
    }

    ll num0 = count(T.cbegin(), T.cend(), '0');

    if(T.at(N - 1) == '0') {
        cout << 10000000000 - num0 + 1 << endl;
        return 0;
    }
    cout << 10000000000 - num0 << endl;
    return 0;
}