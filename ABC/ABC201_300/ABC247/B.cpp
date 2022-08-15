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
    ll N;
    cin >> N;
    vector<string> s(N), t(N);
    for(ll i = 0; i < N; i++) {
        cin >> s.at(i) >> t.at(i);
    }
    for(ll i = 0; i < N; i++) {
        string si = s.at(i);
        string ti = t.at(i);
        bool flag = true;
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(si == s.at(j)) {
                flag = false;
            }
        }
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(si == t.at(j)) {
                flag = false;
            }
        }
        if(flag) {
            continue;
        }
        flag = true;
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(ti == s.at(j)) {
                flag = false;
            }
        }
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            if(ti == t.at(j)) {
                flag = false;
            }
        }
        if(flag) {
            continue;
        }
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}