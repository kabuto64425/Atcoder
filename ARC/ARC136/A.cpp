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
    deque<char> q;
    for(ll i = 0; i < N; i++) {
        if(S.at(i) == 'A') {
            q.push_back('B');
            q.push_back('B');
        } else {
            q.push_back(S.at(i));
        }
    }
    string ans;
    while(q.size() >= 2) {
        char c1 = q.front();
        q.pop_front();
        char c2 = q.front();
        q.pop_front();
        if(c1 == 'B' and c2 == 'B') {
            ans += 'A';
        } else {
            ans += c1;
            q.push_front(c2);
        }
    }
    if(!q.empty()) {
        char c = q.front();
        q.pop_front();
        ans += c;
    }
    
    cout << ans << endl;
    return 0;
}