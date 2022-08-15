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
    string s;
    cin >> s;
    deque<char> deq;
    ll N = s.length();
    for(ll i = 0; i < N; i++) {
        if(!deq.empty()) {
            char b = deq.back();
            if(b == 'B' and s.at(i) == 'C') {
                deq.pop_back();
                deq.push_back('D');
            } else {
                deq.push_back(s.at(i));
            }
        } else {
            deq.push_back(s.at(i));
        }
    }
    ll ans = 0;
    ll current = 0;
    while(!deq.empty()) {
        char c = deq.front();
        deq.pop_front();
        if(c == 'A') {
            current++;
        } else if(c == 'D') {
            ans += current;
        } else {
            current = 0;
        }
    }
    cout << ans << endl;
    return 0;
}