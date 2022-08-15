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

int main(){
    pair<ll, ll> startPosition;
    cin >> startPosition.first >> startPosition.second;
    vector<vector<ll>> t(50, vector<ll>(50));
    ll M = 0;
    for(ll i = 0; i < 50; i++) {
        for(ll j = 0; j < 50; j++) {
            cin >> t.at(i).at(j);
            M = max(M, t.at(i).at(j));
        }
    }

    vector<vector<ll>> p(50, vector<ll>(50));
    for(ll i = 0; i < 50; i++) {
        for(ll j = 0; j < 50; j++) {
            cin >> p.at(i).at(j);
        }
    }

    std::random_device seed_gen;
    std::mt19937 engine {seed_gen()};

    vector<char> ans;
    ll maxScore = 0;

    clock_t start = clock();

    while((long double)(clock() - start) / CLOCKS_PER_SEC < 1.88) {
        vector<bool> flags(3000, false);
        flags.at(t.at(startPosition.first).at(startPosition.second)) = true;
        vector<char> candidate;
        ll score = p.at(startPosition.first).at(startPosition.second);
        pair<ll, ll> s = startPosition;

        while(true) {
            bool isNotAbleDown = s.first + 1 >= 50 or flags.at(t.at(s.first + 1).at(s.second));
            bool isNotAbleRight = s.second + 1 >= 50 or flags.at(t.at(s.first).at(s.second + 1));
            bool isNotAbleUp = s.first - 1 < 0 or flags.at(t.at(s.first - 1).at(s.second));
            bool isNotAbleLeft = s.second - 1 < 0 or flags.at(t.at(s.first).at(s.second - 1));

            vector<char> ds;
            if(!isNotAbleDown) {
                ds.push_back('D');
            }
            if(!isNotAbleRight) {
                ds.push_back('R');
            }
            if(!isNotAbleUp) {
                ds.push_back('U');
            }
            if(!isNotAbleLeft) {
                ds.push_back('L');
            }

            if(isNotAbleDown and isNotAbleRight and isNotAbleUp and isNotAbleLeft) {
                break;
            }

            ll index = rand() % ds.size();
            if(ds.at(index) == 'D') {
                flags.at(t.at(s.first + 1).at(s.second)) = true;
                s.first += 1;
                candidate.push_back('D');
                score += p.at(s.first).at(s.second);
            } else if(ds.at(index) == 'R') {
                flags.at(t.at(s.first).at(s.second + 1)) = true;
                s.second += 1;
                candidate.push_back('R');
                score += p.at(s.first).at(s.second);
            } else if(ds.at(index) == 'U') {
                flags.at(t.at(s.first - 1).at(s.second)) = true;
                s.first -= 1;
                candidate.push_back('U');
                score += p.at(s.first).at(s.second);
            } else if(ds.at(index) == 'L') {
                flags.at(t.at(s.first).at(s.second - 1)) = true;
                s.second -= 1;
                candidate.push_back('L');
                score += p.at(s.first).at(s.second);
            }

            if(score > maxScore) {
                maxScore = score;
                ans = candidate;
            }
        }
    }

    
    
    for(const char &c: ans) {
        cout << c;
    }
    cout << endl;
    return 0;
}