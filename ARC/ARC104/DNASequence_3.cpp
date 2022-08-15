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
    string S;
    cin >> S;
    vector<ll> sumA(N + 1, 0);
    vector<ll> sumG(N + 1, 0);
    vector<ll> sumC(N + 1, 0);
    vector<ll> sumT(N + 1, 0);
    for(ll i = 1; i <= N; i++) {
        sumA.at(i) += sumA.at(i - 1);
        sumG.at(i) += sumG.at(i - 1);
        sumC.at(i) += sumC.at(i - 1);
        sumT.at(i) += sumT.at(i - 1);
        char c = S.at(i - 1);
        if(c == 'A') {
            sumA.at(i)++;
        }else if(c == 'G') {
            sumG.at(i)++;
        }else if(c == 'C') {
            sumC.at(i)++;
        }else if(c == 'T') {
            sumT.at(i)++;
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        for(ll j = i; j <= N; j++) {
            ll A = sumA.at(j) - sumA.at(i - 1);
            ll G = sumG.at(j) - sumG.at(i - 1);
            ll C = sumC.at(j) - sumC.at(i - 1);
            ll T = sumT.at(j) - sumT.at(i - 1);
            if(A == T and G == C) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}