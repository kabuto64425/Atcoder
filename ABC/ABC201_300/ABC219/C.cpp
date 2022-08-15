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
    string X;
    cin >> X;
    ll N;
    cin >> N;
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    map<char, ll> m;
    for(ll i = 0; i < 26; i++) {
        m[X.at(i)] = i;
    }
    sort(ALL(S), [&](string a, string b) {
        ll lengthA = a.length();
        ll lengthB = b.length();
        for(ll i = 0; i < min(lengthA, lengthB); i++) {
            if(a.at(i) != b.at(i)) {
                if(m[a.at(i)] > m[b.at(i)]) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        if(lengthA > lengthB) {
            return false;
        }
        return true;
    });
    for(ll i = 0; i < N; i++) {
        cout << S.at(i) << endl;
    }
    return 0;
}