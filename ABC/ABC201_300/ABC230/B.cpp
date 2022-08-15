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
    bool flag = true;
    for(ll i = 0; i < N; i++) {
        if(i % 3 == 0) {
            if(S.at(i) != 'o') {
                flag = false;
                break;
            }
        } else {
            if(S.at(i) != 'x') {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        cout << "Yes" << endl;
        return 0;
    }
    flag = true;
    for(ll i = 0; i < N; i++) {
        if(i % 3 == 1) {
            if(S.at(i) != 'o') {
                flag = false;
                break;
            }
        } else {
            if(S.at(i) != 'x') {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        cout << "Yes" << endl;
        return 0;
    }
    flag = true;
    for(ll i = 0; i < N; i++) {
        if(i % 3 == 2) {
            if(S.at(i) != 'o') {
                flag = false;
                break;
            }
        } else {
            if(S.at(i) != 'x') {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}