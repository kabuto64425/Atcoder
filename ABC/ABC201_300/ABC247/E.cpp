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

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

int main(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<vector<ll>> vec;
    vector<ll> v;
    for(ll i = 0; i < N; i++) {
        if(A.at(i) < Y or A.at(i) > X) {
            vec.push_back(v);
            v.clear();
        } else {
            v.push_back(A.at(i));
        }
    }
    if(!v.empty()) {
        vec.push_back(v);
    }
    ll ans = 0;
    ll vecSize = vec.size();
    vector<ll> bucket(220000, 0);
    for(ll loop = 0; loop < vecSize; loop++) {
        ll res = 0;
        ll right = 0;
        ll n = vec.at(loop).size();
        vector<ll> v = vec.at(loop);
        for(ll left = 0; left < n; left++) {
            while (right < n && ((bucket.at(X) + ((v.at(right) == X)? 1 : 0) == 0) or (bucket.at(Y) + ((v.at(right) == Y)? 1 : 0) == 0))) {
                bucket.at(v.at(right))++;
                right++;
            }
            res += (n - right);

            if (right == left) right++;
            else bucket.at(v.at(left))--;
        }
        ans += res;
    }
    
    cout << ans << endl;
    return 0;
}