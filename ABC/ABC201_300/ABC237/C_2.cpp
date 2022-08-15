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
    string S;
    cin >> S;
    ll N = S.length();
    ll count1 = 0;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == 'a') {
            count1++;
        } else {
            break;
        }
    }
    ll count2 = 0;
    for(ll i = N - 1; i >= 0; i--) {
        if(S.at(i) == 'a') {
            count2++;
        } else {
            break;
        }
    }
    string T;
    for(ll i = 0; i < count2 - count1; i++) {
        T += 'a';
    }
    T += S;
    ll M = T.length();
    for(ll i = 0; i < M; i++) {
        if(T.at(i) != T.at(M - i - 1)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}