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

ll digsum(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

ll solver(ll N, ll K) {
    vector<bool> seen(100000, false);
    deque<ll> deq;
    ll num = N;
    while(true) {
        if(seen.at(num)) {
            while(deq.front() != num) {
                deq.pop_front();
                K--;

                if(K == 0) {
                    return deq.front();
                }
            }
            break;
        }
        seen.at(num) = true;
        deq.push_back(num);
        num = (num + digsum(num)) % 100000;
    }
    return deq.at(K % deq.size());
}

ll solver2(ll N, ll K) {
    vector<bool> seen(100000, false);
    deque<ll> deq;
    ll num = N;
    while(true) {
        if(seen.at(num)) {
            while(deq.front() != num) {
                deq.pop_front();
                K--;

                if(K == 0) {
                    return deq.front();
                }
            }
            break;
        }
        seen.at(num) = true;
        deq.push_back(num);
        num = (num + digsum(num)) % 100000;
    }
    return deq.at(K % deq.size());
}

int main(){
    ll N, K;
    cin >> N >> K;
    
    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());*/
    
    /*while(true) {
        uniform_int_distribution<ll> dist_N(1, 10), dist_K(1, 10000);
        ll N = dist_N(rnd);
        ll K = dist_K(rnd);
        ll ans1 = solver(N, K);
        ll ans2 = solver2(N, K);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << K << endl;
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/
    
    cout << solver(N, K) << endl;
    //cout << solver2(N, K) << endl;
    return 0;
}