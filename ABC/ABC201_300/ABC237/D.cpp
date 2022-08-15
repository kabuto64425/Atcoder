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
    string S;
    cin >> S;
    deque<ll> deq1, deq2;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == 'L') {
            deq2.push_front(i);
        }
        if(S.at(i) == 'R') {
            deq1.push_back(i);
        }
    }
    while(!deq1.empty()) {
        cout << deq1.front() << " ";
        deq1.pop_front();
    }
    cout << N << " ";
    while(!deq2.empty()) {
        cout << deq2.front() << " ";
        deq2.pop_front();
    }
    cout << endl;
    return 0;
}