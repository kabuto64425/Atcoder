#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

char judge(char a, char b) {
    if(a == b) {
        return a;
    }
    if(a == 'R' and b == 'S') {
        return a;
    }
    if(a == 'S' and b == 'P') {
        return a;
    }
    if(a == 'P' and b == 'R') {
        return a;
    }
    return b;
}

int main(){
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string T;
    T = S + S;
    S = "";
    REP(i, K) {
        REP(j, N) {
            S += judge(T[j * 2], T[j * 2 + 1]);
        }
        T = S + S;
        S = "";
    }
    cout << T[0] << endl;
    return 0;
}