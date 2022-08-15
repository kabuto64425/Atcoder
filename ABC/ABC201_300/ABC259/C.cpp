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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

void compression(const string &S, vector<pair<char, ll>> &res) {
    char pre = S.at(0);
    ll current = 1;
    for(ll i = 1; i < S.length(); i++) {
        if(S.at(i) != pre) {
            res.emplace_back(pre, current);
            pre = S.at(i);
            current = 1;
        } else {
            current++;
        }
    }
    res.emplace_back(pre, current);
    return;
}

int main(){
    string S, T;
    cin >> S >> T;
    vector<pair<char, ll>> p1;
    compression(S, p1);
    vector<pair<char, ll>> p2;
    compression(T, p2);
    if(p1.size() != p2.size()) {
        cout << "No" << endl;
        return 0;
    }
    for(ll i = 0; (ll)i < p1.size(); i++) {
        if(p1.at(i).first != p2.at(i).first) {
            cout << "No" << endl;
            return 0;
        }
        if(p1.at(i).second == 1 and p2.at(i).second != 1) {
            cout << "No" << endl;
            return 0;
        }
        if(p1.at(i).second > p2.at(i).second) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}