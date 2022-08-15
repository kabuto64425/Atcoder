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

using Graph = vector<vector<ll>>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(M);
    for(ll i = 0; i < M; i++) {
        cin >> AB.at(i).first >> AB.at(i).second;
        AB.at(i).first--;
        AB.at(i).second--;
    }

    vector<pair<ll, ll>> CD(M);
    for(ll i = 0; i < M; i++) {
        cin >> CD.at(i).first >> CD.at(i).second;
        CD.at(i).first--;
        CD.at(i).second--;
    }

    vector<ll> P(N);

    sort(ALL(AB));

    for(ll i = 0; i < N; i++) {
        P.at(i) = i;
    }

    do {
        vector<pair<ll, ll>> CDc(M);
        for(ll i = 0; i < M; i++) {
            CDc.at(i).first = P.at(CD.at(i).first);
            CDc.at(i).second = P.at(CD.at(i).second);
            if(CDc.at(i).first > CDc.at(i).second) {
                swap(CDc.at(i).first, CDc.at(i).second);
            }
        }
        sort(ALL(CDc));
        bool flag = true;
        for(ll i = 0; i < M; i++) {
            if(AB.at(i).first != CDc.at(i).first or AB.at(i).second != CDc.at(i).second) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(P.begin(), P.end()));

    cout << "No" << endl;
    return 0;
}