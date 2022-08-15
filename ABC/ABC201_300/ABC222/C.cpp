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

bool sort_by(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> A(2 * N);
    for(ll i = 0; i < 2 * N; i++) {
        cin >> A.at(i);
    }
    vector<pair<ll, ll>> jun(2 * N);
    for(ll i = 0; i < 2 * N; i++) {
        jun.at(i).first = 0;
        jun.at(i).second = i;
    }
    // じゃんけんの勝敗判定
    // https://qiita.com/mpyw/items/3ffaac0f1b4a7713c869
    map<char, ll> te;
    te['G'] = 0;
    te['C'] = 1;
    te['P'] = 2;
    for(ll i = 0; i < M; i++) {
        sort(ALL(jun), sort_by);
        for(ll j = 0; j < N; j++) {
            ll x = jun.at(j * 2).second;
            ll y = jun.at(j * 2 + 1).second;
            ll xt = te[A.at(x).at(i)];
            ll yt = te[A.at(y).at(i)];
            if((xt - yt + 3) % 3 == 2) {
                jun.at(j * 2).first++;
            } else if((xt - yt + 3) % 3 == 1) {
                jun.at(j * 2 + 1).first++;
            }
        }
    }
    sort(ALL(jun), sort_by);
    for(ll i = 0; i < 2 * N; i++) {
        cout << jun.at(i).second + 1 << endl;
    }
    return 0;
}