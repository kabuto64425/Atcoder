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
    ll N, X;
    cin >> N >> X;
    string S;
    cin >> S;
    deque<char> deq;
    for(char &c : S) {
        if(c == 'L' or c == 'R') {
            deq.push_back(c);
        } else if(c == 'U') {
            if(deq.empty()) {
                deq.push_back(c);
                continue;
            }
            char b = deq.back();
            if(b == 'L' or b == 'R') {
                deq.pop_back();
            } else {
                deq.push_back(c);
            }
        }
    }
    ll ans = X;
    while(!deq.empty()) {
        char c = deq.front();
        deq.pop_front();
        if(c == 'L') {
            ans *= 2;
        } else if(c == 'R') {
            ans *= 2;
            ans++;
        } else if(c == 'U') {
            ans /= 2;
        }
    }
    cout << ans << endl;
    return 0;
}