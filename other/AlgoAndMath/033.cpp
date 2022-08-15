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
    long double ax, ay;
    long double bx, by;
    long double cx, cy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    long double a = by - cy;
    long double b = cx - bx;
    long double c = (bx - cx) * by + (cy - by) * bx;

    {
        long double px = (b * b * ax - a * b * ay - a * c) / (long double)(a * a + b * b) + 0.000001;
        long double py = (a * a * ay - a * b * ax - b * c) / (long double)(a * a + b * b) + 0.000001;
        if(px < (long double)min(bx, cx) or px > (long double)max(bx, cx)) {
            long double d1 = sqrtl((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
            long double d2 = sqrtl((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay));
            cout << fixed << setprecision(20) << min(d1, d2) << endl;
            return 0;
        }
    }

    long double denominator = sqrtl(a * a + b * b);
    ll numerator = abs(a * ax + b * ay + c);

    cout << fixed << setprecision(20) << (long double)(numerator) / denominator << endl;

    return 0;
}