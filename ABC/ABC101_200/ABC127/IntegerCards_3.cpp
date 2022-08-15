#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法



int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> vec;
    for(ll i = 0; i < N; i++) {
        ll A;
        cin >> A;
        vec.push_back({A, 1});
    }
    for(ll i = 0; i < M; i++) {
        ll B, C;
        cin >> B >> C;
        vec.push_back({C, B});
    }
    auto comp = [](pair<ll, ll> a, pair<ll, ll> b) {
        return b.first < a.first;
    };
    sort(vec.begin(), vec.end(), comp);
    ll ans = 0;
    ll count = 0;    
    ll index = 0;
    while(count < N) {
        if(count + vec[index].second <= N) {
            ans += vec[index].first * vec[index].second;
            count += vec[index].second;
        } else {
            ans += vec[index].first * (N - count);
            count = N;
        }
        index++;
    }
    cout << ans << endl;
    return 0;
}