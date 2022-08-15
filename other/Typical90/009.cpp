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

long double angle(long double declinationA, long double declinationB) {
    if(abs(declinationA - declinationB) > 180) {
        return 360 - abs(declinationA - declinationB);
    }
    return abs(declinationA - declinationB);
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> XY(N);
    for(pair<ll, ll> &xy : XY) {
        cin >> xy.first >> xy.second;
    }

    long double ans = 0;

    for(ll i = 0; i < N; i++) {
        vector<long double> declinations;
        for(ll j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            long double declination = (atan2l(XY.at(j).second - XY.at(i).second, XY.at(j).first - XY.at(i).first) * 180) / M_PI;
            if(declination < 0) {
                declination += 360;
            }
            declinations.push_back(declination);
        }
        sort(declinations.begin(), declinations.end());
        for(ll j = 0; j < declinations.size(); j++) {
            long double declination = declinations.at(j);
            long double target = declination + 180;
            if(target > 360) {
                target -= 360;
            }
            ll index = lower_bound(declinations.begin(), declinations.end(), target) - declinations.begin();
            if(index == 0) {
                ans = max(ans, angle(declinations.at(index), declination));
                ans = max(ans, angle(declinations.at(declinations.size() - 1), declination));
            } else if(index == declinations.size()) {
                ans = max(ans, angle(declinations.at(index - 1), declination));
                ans = max(ans, angle(declinations.at(0), declination));
            } else {
                ans = max(ans, angle(declinations.at(index), declination));
                ans = max(ans, angle(declinations.at(index - 1), declination));
            }
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}