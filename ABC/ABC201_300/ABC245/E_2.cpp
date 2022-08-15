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
    vector<ll> A(N), B(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for(ll i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    vector<ll> C(M), D(M);
    for(ll i = 0; i < M; i++) {
        cin >> C.at(i);
    }
    for(ll i = 0; i < M; i++) {
        cin >> D.at(i);
    }
    vector<pair<long double, ll>> vec;
    for(ll i = 0; i < N; i++) {
        vec.push_back({-A.at(i), B.at(i)});
    }
    for(ll i = 0; i < M; i++) {
        vec.push_back({-(C.at(i) + 0.5), D.at(i)});
    }
    
    sort(ALL(vec));
    for(ll i = 0; i < vec.size(); i++) {
        vec.at(i) = {-vec.at(i).first, vec.at(i).second};
    }

    multiset<ll> ms;
    for(ll i = 0; i < vec.size(); i++) {
        if(floor(vec.at(i).first) == vec.at(i).first) {
            // チョコ
            multiset<ll>::iterator ite = ms.lower_bound(vec.at(i).second);
            if(ite == ms.end()) {
                cout << "No" << endl;
                return 0;
            }
            ms.erase(ite);
        } else {
            // 箱
            ms.insert(vec.at(i).second);
        }
    }
    cout << "Yes" << endl;
    return 0;
}