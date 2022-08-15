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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<vector<ll>> ans(N * A, vector<ll>(N * B));
    for(ll i = 0; i < N * A; i++) {
        for(ll j = 0; j < N * B; j++) {
            if((i / A) % 2 == 0) {
                if((j / B) % 2 == 0) {
                    ans.at(i).at(j) = 0;
                } else {
                    ans.at(i).at(j) = 1;
                }
            } else {
                if((j / B) % 2 == 0) {
                    ans.at(i).at(j) = 1;
                } else {
                    ans.at(i).at(j) = 0;
                }
            }
        }
    }
    for(ll i = 0; i < N * A; i++) {
        for(ll j = 0; j < N * B; j++) {
            if(ans.at(i).at(j) == 0) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    return 0;
}