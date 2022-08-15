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

long double recur(ll N, ll a, ll b, ll c, vector<vector<vector<long double>>> &dp) {
    if(a == 0 and b == 0 and c == 0) {
        return 0;
    }
    if(dp.at(a).at(b).at(c) != -1) {
        return dp.at(a).at(b).at(c);
    }
    long double res = 0;
    ll zeroCount = N - a - b - c;
    long double p0 = zeroCount / (long double) N;
    long double x = 1 / (1 - p0);
    if(a >= 1) {
        res += recur(N, a - 1, b, c, dp) * (a / (long double) N) * x;
    }
    if(b >= 1) {
        res += recur(N, a + 1, b - 1, c, dp) * (b / (long double) N) * x;
    }
    if(c >= 1) {
        res += recur(N, a, b + 1, c - 1, dp) * (c / (long double) N) * x;
    }
    
    res += x;
    return dp.at(a).at(b).at(c) = res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    vector<vector<vector<long double>>> dp(330, vector<vector<long double>>(330, vector<long double>(330, -1)));
    dp.at(0).at(0).at(0) = 0;
    ll count1 = count(ALL(a), 1);
    ll count2 = count(ALL(a), 2);
    ll count3 = count(ALL(a), 3);
    cout << fixed << setprecision(20) << recur(N, count1, count2, count3, dp) << endl;
    return 0;
}