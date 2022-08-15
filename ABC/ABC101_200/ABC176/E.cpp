#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll H, W, M;
    cin >> H >> W >> M;
    vector<pair<ll, ll>> hw(M);
    for(pair<ll, ll> &elm : hw) {
        cin >> elm.first >> elm.second;
    }
    
    vector<ll> bucketR(H + 1);
    vector<ll> bucketC(W + 1);
    for(const pair<ll, ll> &elm : hw) {
        bucketR.at(elm.first)++;
        bucketC.at(elm.second)++;
    }

    vector<ll> maxRindexes;
    ll maxR = 0;
    for(ll i = 1; i <= H; i++) {
        if(bucketR.at(i) > maxR) {
            maxRindexes.clear();
            maxR = bucketR.at(i);
        }
        if(bucketR.at(i) == maxR) {
            maxRindexes.push_back(i);
        }
    }

    vector<ll> maxCindexes;
    ll maxC = 0;
    for(ll i = 1; i <= W; i++) {
        if(bucketC.at(i) > maxC) {
            maxCindexes.clear();
            maxC = bucketC.at(i);
        }
        if(bucketC.at(i) == maxC) {
            maxCindexes.push_back(i);
        }
    }

    for(ll i = 0; i < (ll) maxRindexes.size(); i++) {
        for(ll j = 0; j < (ll) maxCindexes.size(); j++) {
            bool flag = true;
            for(ll k = 0; k < M; k++) {
                if(maxRindexes.at(i) == hw.at(k).first and maxCindexes.at(j) == hw.at(k).second) {
                    flag = false;
                }
            }
            if(flag) {
                cout << (maxR + maxC) << endl;
                return 0;
            }
        }
    }
    
    cout << (maxR + maxC - 1) << endl;
    return 0;
}