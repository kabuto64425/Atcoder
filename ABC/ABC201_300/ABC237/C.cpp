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
    bool all = true;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) != 'a') {
            all = false;
            break;
        }
    }
    if(all) {
        cout << "Yes" << endl;
        return 0;
    }
    bool flag = false;
    string T;
    ll count1 = 0;
    for(ll i = 0; i < N; i++) {
        if(!flag and S.at(i) == 'a') {
            count1++;
        }
        if(S.at(i) != 'a') {
            flag = true;
        }
        if(flag) {
            T += S.at(i);
        }
    }
    ll M = T.length();
    string U;
    flag = false;
    ll count2 = 0;
    for(ll i = M - 1; i >= 0; i--) {
        if(!flag and T.at(i) == 'a') {
            count2++;
        }
        if(T.at(i) != 'a') {
            flag = true;
        }
        if(flag) {
            U += T.at(i);
        }
    }
    ll L = U.length();
    if(count1 > count2) {
        cout << "No" << endl;
        return 0;
    }
    for(ll i = 0; i < L; i++) {
        if(U.at(i) != U.at(L - i - 1)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}