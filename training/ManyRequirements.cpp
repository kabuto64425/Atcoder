#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void recursive_comb(vector<vector<ll>> &vec,vector<ll> &vec2, ll n, ll k, ll ni, ll ki) {
    if(ni > n) {
        vec.push_back(vec2);
        return;
    }

    for(ll index = ki; index <= k; index++) {
        vec2.at(ni - 1) = index;
        recursive_comb(vec, vec2, n, k, ni + 1, index);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(vector<vector<ll>> &vec, ll n, ll k) {
  vector<ll> vec2(n);
  recursive_comb(vec, vec2, n, k, 1, 1);
}

int main() {
    //入力
    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<ll>> abcd(Q, vector<ll>(4));
    for(ll i = 0; i < Q; i++) {
        for(ll j = 0; j < 4; j++) {
            cin >> abcd.at(i).at(j);
        }
    }

    vector<vector<ll>> vec;
    foreach_comb(vec, N, M);

    ll ans = 0;

    for(ll i = 0; i < vec.size(); i++) {
        ll current = 0;
        vector<ll> vec2 = vec.at(i);
        for(ll j = 0; j < Q; j++) {
            ll a = abcd.at(j).at(0);
            ll b = abcd.at(j).at(1);
            ll c = abcd.at(j).at(2);
            ll d = abcd.at(j).at(3);

            if((vec2.at(b - 1) - vec2.at(a - 1)) == c) {
                current += d;
            }
        }
        ans = max(ans, current);
    }

    cout << ans << endl;
}