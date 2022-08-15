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
    string S;
    string T;
    cin >> S >> T;
    vector<vector<ll>> position(26);
    for(ll i = 0; i < (ll) T.length(); i++) {
        position.at(T.at(i) - 'a').push_back(i);
    }
    for(ll i = 0; i < 26; i++) {
        if(position.at(i).empty()) {
            continue;
        }
        ll index = position.at(i).at(0);
        char s = S.at(index);
        for(ll j = 0; j < (ll) position.at(i).size(); j++) {
            char comps = S.at(position.at(i).at(j));
            if(s != comps) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    vector<vector<ll>> position2(26);
    for(ll i = 0; i < (ll) S.length(); i++) {
        position2.at(S.at(i) - 'a').push_back(i);
    }
    for(ll i = 0; i < 26; i++) {
        if(position2.at(i).empty()) {
            continue;
        }
        ll index = position2.at(i).at(0);
        char t = T.at(index);
        for(ll j = 0; j < (ll) position2.at(i).size(); j++) {
            char compt = T.at(position2.at(i).at(j));
            if(t != compt) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}