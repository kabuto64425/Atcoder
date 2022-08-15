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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> B(N, vector<ll>(M));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < M; j++) {
            cin >> B.at(i).at(j);
        }
    }
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < M; j++) {
            if(i == 0 and j == 0) {
                continue;
            }
            if(i >= 1) {
                if(B.at(i).at(j) - B.at(i - 1).at(j) != 7) {
                    cout << "No" << endl;
                    return 0;
                }
            }
            if(j >= 1) {
                if(B.at(i).at(j) - B.at(i).at(j - 1) != 1) {
                    cout << "No" << endl;
                    return 0;
                }
                if(B.at(i).at(j - 1) % 7 == 0) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}