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

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

const long long INF = 1LL << 60;
const ll MOD = 1000000007; //10^9+7:合同式の法

ll solver(ll N, ll X, vector<ll> &W, ll k) {
    vector<ll> csum(2 * N + 1, 0);
    for(ll i = 1; i <= 2 * N; i++) {
        csum.at(i) = csum.at(i - 1) + W.at((i - 1) % N);
    }

    ll offsetCount = (X - 1) / csum.at(N);

    deque<int> a; // 繰り返しの部分
    vector<bool> seen(N + 1, false); // 一度見たかどうか
    /*seen.at(0) = true;*/
    ll cur = 0;
    vector<ll> count1;
    vector<ll> count2;
    while(true) {
        if(seen.at(cur)) {
            while(a.front() != cur) {
                ll x = a.front();
                a.pop_front();
                if(x > a.front()) {
                    count1.push_back(N - x + a.front());
                } else {
                    count1.push_back((a.front() - x - 1 + N) % N + 1);
                }
            }
            break;
        }

        seen.at(cur) = true;
        a.push_back(cur);
        ll j = lower_bound(ALL(csum), csum.at(cur) + X % csum.at(N)) - csum.begin();
        j %= N;
        cur = j;
    }

    while(!a.empty()) {
        ll x = cur;
        if(x > a.front()) {
            count2.push_back(N - x + a.front());
        } else {
            count2.push_back((a.front() - x - 1 + N) % N + 1);
        }
        cur = a.front();
        a.pop_front();
    }

    if(k <= (ll)count1.size()) {
        return count1.at(k - 1) + offsetCount * N;
    } else {
        k -= count1.size();
        k %= count2.size();
        return count2.at(k) + offsetCount * N;
    }
}

ll solver2(ll N, ll X, vector<ll> &W, ll k) {
    ll cur = 0;
    ll ans = 0;
    for(ll i = 0; i < k; i++) {
        ll current = 0;
        ll count = 0;
        while(current < X) {
            current += W.at(cur);
            cur++;
            cur %= N;
            count++;
        }
        ans = count;
    }
    return ans;
}

int main(){
    ll N, Q, X;
    cin >> N >> Q >> X;
    vector<ll> W(N);
    for(ll i = 0; i < N; i++) {
        cin >> W.at(i);
    }
    vector<ll> K(Q);
    for(ll i = 0; i < Q; i++) {
        cin >> K.at(i);
    }

    /*random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    while(true) {
        uniform_int_distribution<ll> dist_N(1, 3), dist_X(1, 10), dist_W(1, 5), dist_k(1, 10);
        ll N = dist_N(rnd);
        ll X = dist_X(rnd);
        vector<ll> W(N);
        for(ll i=0; i<N; i++) W[i] = dist_W(rnd);
        ll k = dist_k(rnd);
        ll ans1 = solver(N, X, W, k);
        ll ans2 = solver2(N, X, W, k);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << X << endl;
            for(int i=0; i<N; i++) cout << W[i] << " \n"[i==N-1];
            cout << k << endl;
            cout << ans1 << endl;
            cout << ans2 << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/

    for(ll i = 0; i < Q; i++) {
        cout << solver(N, X, W, K.at(i)) << endl;
    }

    return 0;
}