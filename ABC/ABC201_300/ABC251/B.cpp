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
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<ll> bucket(W + 1);
    for(ll i = 0; i < N; i++) {
        if(A.at(i) <= W) {
            bucket.at(A.at(i))++;
        }
    }
    if(N >= 2) {
        for(ll i = 0; i < N; i++) {
            for(ll j = i + 1; j < N; j++) {
                if(A.at(i) + A.at(j) <= W) {
                    bucket.at(A.at(i) + A.at(j))++;
                }
            }
        }
    }
    if(N >= 3) {
        for(ll i = 0; i < N; i++) {
            for(ll j = i + 1; j < N; j++) {
                for(ll k = j + 1; k < N; k++) {
                    if(A.at(i) + A.at(j) + A.at(k) <= W) {
                        bucket.at(A.at(i) + A.at(j) + A.at(k))++;
                    }
                }
            }
        }
    }

    ll ans = 0;

    for(ll i = 1; i <= W; i++) {
        if(bucket.at(i) >= 1) {
            ans++;
        }
    }
    
    
    cout << ans << endl;
    return 0;
}