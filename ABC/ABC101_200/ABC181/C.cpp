#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

signed main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> xy(N);
    REP(i, N) {
        cin >> xy.at(i).first >> xy.at(i).second;
    }
    FOR(i, 0, N - 3) {
        FOR(j, i + 1, N - 2) {
            FOR(k, j + 1, N - 1) {
                pair<ll, ll> a = {xy.at(j).first - xy.at(i).first, xy.at(j).second - xy.at(i).second};
                pair<ll, ll> b = {xy.at(k).first - xy.at(i).first, xy.at(k).second - xy.at(i).second};
                if(a.first == 0 & b.first == 0) {
                    cout << "Yes" << endl;
                    return 0;
                } else if (a.second == 0 & b.second == 0){
                    cout << "Yes" << endl;
                    return 0;
                } else {
                    if(a.first * b.second == a.second * b.first) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}