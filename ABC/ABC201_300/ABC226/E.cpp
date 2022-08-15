#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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

using Graph = vector<vector<ll>>;

mint solver(ll N, ll M, const vector<ll> U, const vector<ll> V) {
    dsu d(N);
    vector<bool> flags(N);
    vector<pair<ll, ll>> edges(M);
    for(ll i = 0; i < M; i++) {
        if(d.same(U.at(i), V.at(i))) {
            if(flags.at(d.leader(U.at(i)))) {
                return 0;
            }
            d.merge(U.at(i), V.at(i));
            flags.at(d.leader(U.at(i))) = true;
        } else {
            if(flags.at(d.leader(U.at(i))) and flags.at(d.leader(V.at(i)))) {
                return 0;
            }
            if(flags.at(d.leader(U.at(i))) or flags.at(d.leader(V.at(i)))) {
                flags.at(d.leader(U.at(i))) = false;
                flags.at(d.leader(V.at(i))) = false;
                d.merge(U.at(i), V.at(i));
                flags.at(d.leader(U.at(i))) = true;
            } else {
                d.merge(U.at(i), V.at(i));
            }
        }
    }
    for(ll i = 0; i < N; i++) {
        if(!flags.at(d.leader(i))) {
            return 0;
        }
    }
    mint ans = 2;
    ll groupSize = d.groups().size();
    return ans.pow(groupSize);
}

mint solver2(ll N, ll M, const vector<ll> U, const vector<ll> V) {
    bitset<20> s(N);
    mint ans = 0;
    for(ll bit = 0; bit < (1 << M); bit++) {
        Graph G(N);
        bitset<20> s(bit);
        for(ll i = 0; i < M; i++) {
            if(s.test(i)) {
                G[U.at(i)].push_back(V.at(i));
            } else {
                G[V.at(i)].push_back(U.at(i));
            }
        }
        bool flag = true;
        for(ll i = 0; i < N; i++) {
            if(G.at(i).size() != 1) {
                flag = false;
            }
        }
        if(flag) {
            ans++;
        }
    }
    return ans;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> U(M), V(M);
    for(ll i = 0; i < M; i++) {
        cin >> U.at(i) >> V.at(i);
        U.at(i)--;
        V.at(i)--;
    }
    
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    /*while(true) {
        uniform_int_distribution<ll> dist_N(2, 6);
        ll N = dist_N(rnd);
        uniform_int_distribution<ll> dist_M(1, min(10LL, N * (N - 1) / 2));
        ll M = dist_M(rnd);
        set<pair<ll, ll>> s;
        uniform_int_distribution<ll> dist_UV(0, N - 1);
        while(s.size() < M) {
            ll x = dist_UV(rnd);
            ll y = dist_UV(rnd);
            if(x == y) {
                continue;
            }
            ll U = min(x, y);
            ll V = max(x, y);
            s.insert({U, V});
        }
        vector<ll> U, V;
        for(pair<ll, ll> p : s) {
            U.push_back(p.first);
            V.push_back(p.second);
        }
        mint ans1 = solver(N, M, U, V);
        mint ans2 = solver2(N, M, U, V);
        if(ans1 != ans2) {
            cout << "NG" << endl;
            cout << N << " " << M << endl;
            for(int i=0; i<M; i++) {
                cout << U.at(i) + 1 << " " << V.at(i) + 1 << endl;
            };
            cout << ans1.val() << endl;
            cout << ans2.val() << endl;
            break;
        } else {
            cout << "OK" << endl;
        }
    }*/

    cout << solver(N, M, U, V).val() << endl;
    //cout << solver2(N, M, U, V).val() << endl;
    return 0;
}