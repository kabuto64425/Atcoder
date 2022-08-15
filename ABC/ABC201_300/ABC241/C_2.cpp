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
    vector<string> S(N);
    for(ll i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            if(i + 5 < N) {
                ll count = 0;
                for(ll k = 0; k < 6; k++) {
                    if(S.at(i + k).at(j) == '#') {
                        count++;
                    }
                }
                if(count >= 4) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if(j + 5 < N) {
                ll count = 0;
                for(ll k = 0; k < 6; k++) {
                    if(S.at(i).at(j + k) == '#') {
                        count++;
                    }
                }
                if(count >= 4) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if(i + 5 < N and j + 5 < N) {
                ll count = 0;
                for(ll k = 0; k < 6; k++) {
                    if(S.at(i + k).at(j + k) == '#') {
                        count++;
                    }
                }
                if(count >= 4) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if(i + 5 < N and j - 5 >= 0) {
                ll count = 0;
                for(ll k = 0; k < 6; k++) {
                    if(S.at(i + k).at(j - k) == '#') {
                        count++;
                    }
                }
                if(count >= 4) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}