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

struct Point {
    long long px, py;
};

Point operator+(const Point& a1, const Point& a2) {
    return Point{ a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
    return Point{ a1.px - a2.px, a1.py - a2.py };
}

bool operator<(const Point& a1, const Point& a2) {
    if (a1.px < a2.px) return true;
    if (a1.px > a2.px) return false;
    if (a1.py < a2.py) return true;
    return false;
}

// 点 p1 と p2 の外積を求める
long long crs(Point p1, Point p2) {
    return p1.px * p2.py - p1.py * p2.px;
}

long long gcd_for_currenct_problem(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    // Step #1. 入力
    ll N;
    cin >> N;
    vector<Point> G(N + 1);
    for(ll i = 1; i <= N; i++) {
        cin >> G[i].px >> G[i].py;
    }
    sort(G.begin(), G.end());

    // Step #2. 凸包を求める
    vector<Point> G1, G2, Totsuhou;
    G1.push_back(G[1]); G2.push_back(G[1]);
    G1.push_back(G[2]); G2.push_back(G[2]);
    for (int i = 3; i <= N; i++) {
        while (G1.size() >= 2 && crs(G1[G1.size() - 1] - G1[G1.size() - 2], G[i] - G1[G1.size() - 1]) <= 0) G1.pop_back();
        while (G2.size() >= 2 && crs(G2[G2.size() - 1] - G2[G2.size() - 2], G[i] - G2[G2.size() - 1]) >= 0) G2.pop_back();
        G1.push_back(G[i]);
        G2.push_back(G[i]);
    }
    for (int i = 0; i < G1.size(); i++) Totsuhou.push_back(G1[i]);
    for (int i = (int)G2.size() - 2; i >= 1; i--) Totsuhou.push_back(G2[i]);

    // Step #3. 辺上の格子点の数を求める
    ll EdgePoint = Totsuhou.size();
    for (int i = 0; i < Totsuhou.size(); i++) {
        ll ax = Totsuhou[(i + 0) % Totsuhou.size()].px, ay = Totsuhou[(i + 0) % Totsuhou.size()].py;
        ll bx = Totsuhou[(i + 1) % Totsuhou.size()].px, by = Totsuhou[(i + 1) % Totsuhou.size()].py;
        ll vx = abs(bx - ax);
        ll vy = abs(by - ay);
        ll r = gcd_for_currenct_problem(vx, vy);
        EdgePoint += (r - 1LL);
    }

    // Step #4. 多角形の面積（を 2 倍した値）を求める
    ll Area = 0;
    for (int i = 0; i < Totsuhou.size(); i++) {
        ll ax = Totsuhou[(i + 0) % Totsuhou.size()].px, ay = Totsuhou[(i + 0) % Totsuhou.size()].py;
        ll bx = Totsuhou[(i + 1) % Totsuhou.size()].px, by = Totsuhou[(i + 1) % Totsuhou.size()].py;
        Area += (bx - ax) * (by + ay);
    }
    Area = abs(Area);

    // N: 辺上の格子点の数 + 凸包の内部の点の数
    // そのため、「(EdgePoint / 2) - N = -(EdgePoint / 2) - 凸包の内部の点の数」となるので、
    // 最初の処理はEdgePointを足しているが、
    // ピックの定理によって求めた内部の点の数 - 凸包の内部の点の数を求めることができる。
    ll ans = Area + EdgePoint + 2LL;
    ans = (ans / 2LL) - N;

    cout << ans << endl;
    return 0;
}