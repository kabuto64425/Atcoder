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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<pair<ll, ll>> AB(N);
    for(pair<ll, ll> &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    map<ll, vector<ll>> X;
    for(ll i = 0; i < N; i++) {
        X[AB.at(i).first].push_back(i);
        //X.at(i).first = AB.at(i).first;
        //X.at(i).second = i + 1;
    }
    map<ll, vector<ll>> Y;
    for(ll i = 0; i < N; i++) {
        Y[AB.at(i).second].push_back(i);
        //X.at(i).first = AB.at(i).first;
        //X.at(i).second = i + 1;
    }

    vector<pair<ll, ll>> ans(N);
    ll i = 0;
    for (auto elm : X) {
        for(ll j = 0; j < elm.second.size(); j++) {
            ans.at(elm.second.at(j)).first = i + 1;
        }
        i++;
    }

    i = 0;
    for (auto elm : Y) {
        for(ll j = 0; j < elm.second.size(); j++) {
            ans.at(elm.second.at(j)).second = i + 1;
        }
        i++;
    }

    for(const pair<ll, ll> &elm : ans) {
        cout << elm.first << " " << elm.second << endl;
    }

    return 0;
}