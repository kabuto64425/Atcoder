#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000000000;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll findCoefficient(ll N, ll index, const vector<ll> &cumulativeSumF, const vector<ll> &cumulativeProductG) {
    if(cumulativeSumF.at(N) - cumulativeSumF.at(index) - cumulativeSumF.at(N - index) >= 1) {
        return 0;
    }
    if(cumulativeProductG.at(N) == 1) {
        if((cumulativeProductG.at(index) * cumulativeProductG.at(N - index)) % 3 == 1) {
            return 1;
        } else {
            return 2;
        }
    }
    if((cumulativeProductG.at(index) * cumulativeProductG.at(N - index)) % 3 == 1) {
        return 2;
    } else {
        return 1;
    }
}

int main(){
    ll N;
    cin >> N;
    string C;
    cin >> C;
    vector<ll> nums(N);
    for(ll i = 0; i < N; i++) {
        if(C.at(i) == 'B') {
            nums.at(i) = 0;
        } else if(C.at(i) == 'W') {
            nums.at(i) = 1;
        } else if(C.at(i) == 'R') {
            nums.at(i) = 2;
        }
    }

    vector<ll> cumulativeSumF(400001);
    cumulativeSumF.at(0) = 0;
    for(ll i = 1; i <= 400000; i++) {
        ll loop = 0;
        ll m = i;
        while(m % 3 == 0) {
            m /= 3;
            loop++;
        }
        cumulativeSumF.at(i) = cumulativeSumF.at(i - 1) + loop;
    }

    vector<ll> cumulativeProductG(400001);
    cumulativeProductG.at(0) = 1;
    for(ll i = 1; i <= 400000; i++) {
        ll m = i;
        while(m % 3 == 0) {
            m /= 3;
        }
        cumulativeProductG.at(i) = (cumulativeProductG.at(i - 1) * (m % 3)) % 3;
    }

    ll ans = 0;

    for(ll i = 0; i < N; i++) {
        ans += (nums.at(i) * findCoefficient(N - 1, i, cumulativeSumF, cumulativeProductG)) % 3;
        ans = ans % 3;
    }

    if(N % 2 == 0) {
        ans = (-ans + 3) % 3;
    }

    if(ans == 0) {
        cout << "B" << endl;
    } else if(ans == 1) {
        cout << "W" << endl;
    } else if(ans == 2) {
        cout << "R" << endl;
    }

    return 0;
}