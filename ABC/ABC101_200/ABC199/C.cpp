#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<tuple<ll, ll, ll>> TAB(Q);
    for(tuple<ll, ll, ll> &tab : TAB) {
        cin >> get<0>(tab) >> get<1>(tab) >> get<2>(tab);
    }
    string S1 = S.substr(0, N);
    string S2 = S.substr(N, N);
    for(const tuple<ll, ll, ll> &tab : TAB) {
        if(get<0>(tab) == 1) {
            char a;
            if(get<1>(tab) > N) {
                a = S2.at(get<1>(tab) - N - 1);
            } else {
                a = S1.at(get<1>(tab) - 1);
            }
            char b;
            if(get<2>(tab) > N) {
                b = S2.at(get<2>(tab) - N - 1);
            } else {
                b = S1.at(get<2>(tab) - 1);
            }

            if(get<1>(tab) > N) {
                S2.at(get<1>(tab) - N - 1) = b;
            } else {
                S1.at(get<1>(tab) - 1) = b;
            }
            if(get<2>(tab) > N) {
                S2.at(get<2>(tab) - N - 1) = a;
            } else {
                S1.at(get<2>(tab) - 1) = a;
            }
        } else {
            S1.swap(S2);
        }
    }
    cout << S1;
    cout << S2;
    cout << endl;
    return 0;
}