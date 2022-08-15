#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)

const ll INF = 1000000000000; //10^12:∞
const ll MOD = 1000000007; //10^9+7:合同式の法

ll culcSatisfaction(const ll D, const vector<ll> c, const vector<vector<ll>> s, const vector<ll> contests) {
    ll satisfaction = 0;
    vector<ll> last(26);

    for(ll d = 1; d <= D; d++) {
        ll contest = contests.at(d - 1);
        satisfaction += s.at(d - 1).at(contest - 1);
        last.at(contest - 1) = d;
        for(ll i = 1; i <= 26; i++) {
            satisfaction -= c.at(i - 1) * (d - last.at(i - 1));
        }

    }
    return satisfaction;
}

int main(){
    clock_t start = clock();
    ll D;
    cin >> D;
    vector<ll> c(26);
    vector<vector<ll>> s(D, vector<ll>(26));
    for(ll &elm : c) {
        cin >> elm;
    }
    for(vector<ll> &vec : s) {
        for(ll & elm : vec) {
            cin >> elm;
        }
    }

    mt19937 mt{ std::random_device{}() };
    uniform_int_distribution<int> distContest(1, 26);
    uniform_int_distribution<int> distDay(1, D);
    vector<ll> answer(D);

    for(ll d = 1; d <= D; d++) {
        vector<ll> sd = s.at(d - 1);
        vector<ll>::iterator iter = std::max_element(sd.begin(), sd.end());
        ll index = distance(sd.begin(), iter);
        answer.at(d - 1) = index + 1;
    }

    ll maxSatisfaction = culcSatisfaction(D, c, s, answer);

    while((long double)(clock() - start) / CLOCKS_PER_SEC < 1.90) {
        vector<ll> contests = answer;
        ll changeDay = distDay(mt);
        ll changeContest = distContest(mt);
        contests.at(changeDay - 1) = changeContest;
        ll afterSatisfaction = culcSatisfaction(D, c, s, contests);
        if(afterSatisfaction >= maxSatisfaction) {
            maxSatisfaction = afterSatisfaction;
            answer = contests;
        }
    }

    for(const ll &elm : answer) {
        cout << elm << endl;
    }
    return 0;
}