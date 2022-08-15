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
    ll N;
    cin >> N;
    vector<tuple<ll, ll, ll>> xy(N);
    for(ll i = 0; i < N; i++) {
        cin >> get<0>(xy.at(i)) >> get<1>(xy.at(i));
        get<2>(xy.at(i)) = i;
    }
    
    vector<tuple<ll, ll, ll>> yx(N);
    for(ll i = 0; i < N; i++) {
        yx.at(i) = {get<1>(xy.at(i)), get<0>(xy.at(i)), i};
    }
    
    sort(xy.begin(), xy.end());
    sort(yx.begin(), yx.end());

    vector<tuple<ll, ll, ll>> a;
    a.push_back({get<0>(xy.at(N - 1)) - get<0>(xy.at(0)), get<2>(xy.at(N - 1)), get<2>(xy.at(0))});
    a.push_back({get<0>(xy.at(N - 2)) - get<0>(xy.at(0)), get<2>(xy.at(N - 2)), get<2>(xy.at(0))});
    a.push_back({get<0>(xy.at(N - 1)) - get<0>(xy.at(1)), get<2>(xy.at(N - 1)), get<2>(xy.at(1))});
    

    a.push_back({get<0>(yx.at(N - 1)) - get<0>(yx.at(0)), get<2>(yx.at(N - 1)), get<2>(yx.at(0))});
    a.push_back({get<0>(yx.at(N - 2)) - get<0>(yx.at(0)), get<2>(yx.at(N - 2)), get<2>(yx.at(0))});
    a.push_back({get<0>(yx.at(N - 1)) - get<0>(yx.at(1)), get<2>(yx.at(N - 1)), get<2>(yx.at(1))});

    sort(a.begin(), a.end());
    if(get<1>(a.at(5)) == get<1>(a.at(4)) and get<2>(a.at(5)) == get<2>(a.at(4))) {
        cout << get<0>(a.at(3)) << endl;
        return 0;
    }
    cout << get<0>(a.at(4)) << endl;
    return 0;
}