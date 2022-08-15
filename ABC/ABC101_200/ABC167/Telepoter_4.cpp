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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(ll &a : A) {
        cin >> a;
        a--;
    }
    deque<ll> deq;
    vector<bool> seen(N, false);
    ll cur = 0;
    seen.at(cur) = true;
    deq.push_back(cur);

    while(true) {
        cur = A.at(cur);
        if(seen.at(cur)) {
            break;
        }
        seen.at(cur) = true;
        deq.push_back(cur);
    }
    ll mcur = deq.front();
    while(true) {
        if(K == 0) {
            cout << mcur + 1 << endl;
            return 0;
        }
        if(mcur == cur) {
            break;
        }
        deq.pop_front();
        K--;
        mcur = deq.front();
    }
    cout << deq[K % deq.size()] + 1 << endl;
    return 0;
}