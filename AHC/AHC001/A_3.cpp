#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

bool isHit(const tuple<ll, ll, ll, ll> rect1, const tuple<ll, ll, ll, ll> rect2) {
    ll mx1 = get<0>(rect1);
    ll my1 = get<1>(rect1);
    ll mx2 = get<2>(rect1);
    ll my2 = get<3>(rect1);

    ll ex1 = get<0>(rect2);
    ll ey1 = get<1>(rect2);
    ll ex2 = get<2>(rect2);
    ll ey2 = get<3>(rect2);

    if(mx1 < ex2 && ex1 < mx2 && my1 < ey2 && ey1 < my2) {
        return true;
    }
    return false;
}

ll culc(const ll n, const vector<tuple<ll, ll, ll>> xyr, const vector<tuple<ll, ll, ll, ll>> abcd) {

    for(ll i = 0; i <= n - 2; i++) {
        for(ll j = i + 1; j <= n - 1; j++) {
            tuple<ll, ll, ll, ll> rect1 = abcd.at(i);
            tuple<ll, ll, ll, ll> rect2 = abcd.at(j);
            if(isHit(rect1, rect2)) {
                return 0;
            }
        }
    }

    long double score = 0;
    for(ll i = 0; i < n; i++) {
        tuple<ll, ll, ll> elmXyr = xyr.at(i);
        tuple<ll, ll, ll, ll> elmAbcd = abcd.at(i);
        if(get<0>(elmAbcd) > get<0>(elmXyr) or get<2>(elmAbcd) <= get<0>(elmXyr) or get<1>(elmAbcd) > get<1>(elmXyr) or get<3>(elmAbcd) <= get<1>(elmXyr)) {
            continue;
        }
        ll s = abs(get<2>(elmAbcd) - get<0>(elmAbcd)) * abs(get<3>(elmAbcd) - get<1>(elmAbcd));
        ll r = get<2>(elmXyr);
        long double p = 1 - (1 - min(r, s) / (long double) max(r, s)) * (1 - min(r, s) / (long double) max(r, s));
        score += p;
    }
    score *= 1000000000;
    score /= n;
    return (long long)score;
}

int main(){
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll>> xyr(n);
    for(auto &elm : xyr) {
        cin >> get<0>(elm) >> get<1>(elm) >> get<2>(elm);
    }

    vector<tuple<ll, ll, ll, ll>> abcd;

    for(ll i = 0; i < n; i++) {
        const auto elm = xyr.at(i);
        long double length = sqrtl(get<2>(elm));
        ll x1 = ceil(get<0>(elm) - length / 2);
        ll y1 = ceil(get<1>(elm) - length / 2);
        ll x2 = ceil(get<0>(elm) + length / 2);
        ll y2 = ceil(get<1>(elm) + length / 2);
        
        x1 = max(x1, 0LL);
        y1 = max(y1, 0LL);
        x2 = min(x2, 10000LL);
        y2 = min(y2, 10000LL);
        
        while(true) {
            bool flag = true;
            for(ll j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                tuple<ll, ll, ll> xy = xyr.at(j);
                ll x = get<0>(xy);
                ll y = get<1>(xy);
                if(isHit({x1, y1, x2, y2}, {x, y, x + 1, y + 1})) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(const auto elm2 : abcd) {
                    if(isHit({x1, y1, x2, y2}, elm2)) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                abcd.push_back({x1, y1, x2, y2});
                break;
            } else{
                x1 = min(x1 + 1, get<0>(elm));
                y1 = min(y1 + 1, get<1>(elm));
                x2 = min(max(x2 - 1, get<0>(elm) + 1), 10000LL);
                y2 = min(max(y2 - 1, get<1>(elm) + 1), 10000LL);
            }
        }
    }

    for(const auto elm : abcd) {
        cout << get<0>(elm) << " " << get<1>(elm) << " " << get<2>(elm) << " " << get<3>(elm) << endl;
    }
    return 0;
}