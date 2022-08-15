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

bool sort_by(tuple<ll, ll, bool> a, tuple<ll, ll, bool> b) {
    if(get<0>(a) == get<0>(b)) {
        if(get<2>(a) and !get<2>(b)) {
            return false;
        }
        if(!get<2>(a) and get<2>(b)) {
            return true;
        }
    }
    return get<0>(a) > get<0>(b);
}

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
    vector<tuple<ll, ll, bool>> vec(N + M);
    for(ll i = 0; i < N; i++) {
        vec.at(i) = {A.at(i), B.at(i), true};
    }
    for(ll i = 0; i < M; i++) {
        vec.at(N + i) = {C.at(i), D.at(i), false};
    }
    sort(ALL(vec), sort_by);
    multiset<ll> ms;
    for(ll i = 0; i < N + M; i++) {
        tuple<ll, ll, bool> elm = vec.at(i);
        if(get<2>(elm)) {
            multiset<ll>::iterator ite = ms.lower_bound(get<1>(elm));
            if(ite == ms.end()) {
                cout << "No" << endl;
                return 0;
            }
            ms.erase(ite);
        } else {
            ms.insert(get<1>(elm));
        }
    }
    cout << "Yes" << endl;
    return 0;
}