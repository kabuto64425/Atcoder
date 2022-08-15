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
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> AB(N);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    sort(AB.begin(), AB.end());
    ll rest = K;
    ll index = 0;
    ll position = 0;
    while(true) {
        if(index < N and position + rest >= AB.at(index).first) {
            rest -= AB.at(index).first - position;
            position = AB.at(index).first;
            rest += AB.at(index).second;
        } else {
            position += rest;
            rest = 0;
            break;
        }
        index++;
    }
    cout << position << endl;
    return 0;
}