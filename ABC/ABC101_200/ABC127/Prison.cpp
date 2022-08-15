#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> vec(M);

    for(ll i = 0; i < M; i++) {
        cin >> vec.at(i).first >> vec.at(i).second;
    }

    ll left = 1;
    ll right = N;
    for(ll i = 0; i < M; i++) {
        left = max(left, vec.at(i).first);
        right = min(right, vec.at(i).second);
    }

    cout << max((ll)0, (right - left + 1)) << endl;
}