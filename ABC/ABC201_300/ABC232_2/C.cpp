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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> AB(M);
    vector<pair<ll, ll>> CD(M);
    for(ll i = 0; i < M; i++) {
        cin >> AB.at(i).first >> AB.at(i).second;
        AB.at(i).first--;
        AB.at(i).second--;
    }
    for(ll i = 0; i < M; i++) {
        cin >> CD.at(i).first >> CD.at(i).second;
        CD.at(i).first--;
        CD.at(i).second--;
    }

    sort(ALL(AB));

    vector<ll> P(N);
    for(ll i = 0; i < N; i++) {
        P.at(i) = i;
    }
    do {
        vector<pair<ll, ll>> nCD(M);
        for(ll i = 0; i < M; i++) {
            nCD.at(i).first = P.at(CD.at(i).first);
            nCD.at(i).second = P.at(CD.at(i).second);
            if(nCD.at(i).first > nCD.at(i).second) {
                swap(nCD.at(i).first, nCD.at(i).second);
            }
        }
        sort(ALL(nCD));
        bool flag = true;
        for(ll i = 0; i < M; i++) {
            if(AB.at(i) != nCD.at(i)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(ALL(P)));
    cout << "No" << endl;
    return 0;
}