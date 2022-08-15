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

pair<ll, ll> culcVec(pair<ll, ll> startPoint, pair<ll, ll> endPoint) {
    return {endPoint.first - startPoint.first, endPoint.second - startPoint.second};
}

/*
 ベクトルの外積 v1 × v2 を求める
 2次平面のため、外積はスカラー量になる
 */
ll crossProduct(pair<ll, ll> v1, pair<ll, ll> v2) {
    return v1.first * v2.second - v1.second * v2.first;
}

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> XY(N);
    for(pair<ll, ll> &xy : XY) {
        cin >> xy.first >> xy.second;
    }
    ll ans = 0;
    for(ll ty = 0; ty <= 1000; ty++) {
        for(ll tx = 0; tx <= 1000; tx++) {
            pair<ll, ll> A = XY.at(0);
            pair<ll, ll> B = XY.at(1);
            pair<ll, ll> C = XY.at(2);

            pair<ll, ll> P = {tx, ty};

            pair<ll, ll> CAvec = culcVec(C, A);
            pair<ll, ll> ABvec = culcVec(A, B);
            pair<ll, ll> BCvec = culcVec(B, C);

            pair<ll, ll> APvec = culcVec(A, P);
            pair<ll, ll> BPvec = culcVec(B, P);
            pair<ll, ll> CPvec = culcVec(C, P);

            ll cp1 = crossProduct(CAvec, APvec);
            ll cp2 = crossProduct(ABvec, BPvec);
            ll cp3 = crossProduct(BCvec, CPvec);

            if((cp1 >= 0 and cp2 >= 0 and cp3 >= 0) or (cp1 <= 0 and cp2 <= 0 and cp3 <= 0)) {
                ans++;
            }
        }
    }
    ans -= 3;
    cout << ans << endl;
    return 0;
}