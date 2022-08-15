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
    string S, T;
    cin >> S >> T;
    ll N = (ll)S.length();
    for(ll i = 0; i < 26; i++) {
        bool flag = true;
        for(ll j = 0; j < N; i-j++) {
            char c = (char)((((S.at(j) + i - 'a')) % 26) + 'a');
            if(T.at(j) != c) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}