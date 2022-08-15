#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) x.begin(),x.end()

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int count_number(const vector<vector<ll>> &A, const ll N, const ll P, ll lens) {
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == -1) dist[i][j] = lens;
            if (A[i][j] != -1) dist[i][j] = A[i][j];
        }
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if(dist[i][j] <= P) {
                res++;
            }
        }
    }
    return res;
}

int main(){
    ll N, P, K;
    cin >> N >> P >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            cin >> A.at(i).at(j);
        }
    }
    
    ll ok = 0;
    ll ng = INF;
    while(abs(ng - ok) != 1) {
        ll mid = (ok + ng) / 2;
        ll k = count_number(A, N, P, mid);
        if(k >= (K + 1)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    ll L = ok;
    
    ok = 0;
    ng = INF;
    while(abs(ng - ok) != 1) {
        ll mid = (ok + ng) / 2;
        ll k = count_number(A, N, P, mid);
        if(k >= K) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    ll R = ok;
    
    if(L > (ll)(1e10)) {
        cout << 0 << endl;
        return 0;
    }
    
    if(R > (ll)(1e10)) {
        cout << "Infinity" << endl;
        return 0;
    }
    
    cout << R - L << endl;
}