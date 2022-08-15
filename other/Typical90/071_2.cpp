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

using Graph = vector<vector<ll>>;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M), B(M);
    for(ll i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    Graph G(N);
    vector<ll> deg(N);
    for(ll i = 0; i < M; i++) {
        G[A.at(i)].push_back(B.at(i));
        deg[B.at(i)]++;
    }
    vector<ll> st;
    vector<ll> perm(N, -1);
    vector<vector<ll>> answer_list;
    function<bool(ll)> dfs = [&](ll depth) {
        if (depth == N) {
            answer_list.push_back(perm);
            return true;
        }
        if (st.empty()) {
            return false;
        }
        for (ll i = ll(st.size()) - 1; i >= 0; --i) {
            if (answer_list.size() == K) {
                break;
            }
            ll x = st[i];
            st.erase(st.begin() + i);
            for (ll j : G[x]) {
                --deg[j];
                if (deg[j] == 0) {
                    st.push_back(j);
                }
            }
            perm[depth] = x;
            bool sign = dfs(depth + 1);
            if (!sign) {
                return false;
            }
            for (ll j : G[x]) {
                if (deg[j] == 0) {
                    st.pop_back();
                }
                ++deg[j];
            }
            st.insert(st.begin() + i, x);
        }
        return true;
    };
    for (ll i = 0; i < N; ++i) {
        if (deg[i] == 0) {
            st.push_back(i);
        }
    }
    dfs(0);
    if (answer_list.size() != K) {
        cout << -1 << endl;
    }
    else {
        for (vector<ll> v : answer_list) {
            for (ll i = 0; i < N; ++i) {
                if (i != 0) cout << ' ';
                cout << v[i] + 1;
            }
            cout << endl;
        }
    }
    return 0;
}