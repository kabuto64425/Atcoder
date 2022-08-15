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

int main(){
    ll N;
    cin >> N;
    ll x0, y0;
    cin >> x0 >> y0;
    ll xn2, yn2;
    cin >> xn2 >> yn2;
    long double deg = 360 / (long double) N;
    long double xcenter = (x0 + xn2) / (long double) 2;
    long double ycenter = (y0 + yn2) / (long double) 2;

    long double x0Translated = x0 - xcenter;
    long double y0Translated = y0 - ycenter;

    long double sinTheta = sin(M_PI * deg / (long double) 180);
    long double cosTheta = cos(M_PI * deg / (long double) 180);
    
    long double xans = x0Translated * cosTheta - y0Translated * sinTheta;
    long double yans = x0Translated * sinTheta + y0Translated * cosTheta;
    xans += xcenter;
    yans += ycenter;
    cout << fixed << setprecision(20) << xans << " " << yans << endl;
    return 0;
}