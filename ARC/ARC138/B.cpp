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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    deque<ll> deq;
    for(ll i = 0; i < N; i++) {
        deq.push_back(A.at(i));
    }
    bool isFlip = false;
    while(!deq.empty()) {
        ll x = isFlip? 1 : 0;
        if(deq.back() == x) {
            deq.pop_back();
        } else {
            if(deq.front() == x) {
                deq.pop_front();
                isFlip = !isFlip;
            } else {
                break;
            }
        }
    }
    if(deq.empty()) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}