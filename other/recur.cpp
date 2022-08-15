#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

void recur(ll d, ll x, vector<ll> &nums) {
    nums.push_back(x);
    if(d == 0) {
        return;
    }
    REP(i, 10) {
        recur(d - 1, x * 10 + i, nums);
    }
}

signed main(){
    vector<ll> nums;
    recur(3, 0, nums);
    sort(nums.begin(), nums.end());
    for(auto elm : nums) {
        cout << elm << endl;
    }
}