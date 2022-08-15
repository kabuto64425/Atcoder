#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> points(N);

    for(ll i = 0; i < N; i++) {
        vector<ll> point(2);
        cin >> point.at(0) >> point.at(1);
        points.at(i) = point;
    }

    vector<ll> jun(N);

    for(ll i = 0; i < N; i++) {
        jun.at(i) = i;
    }

    long double sum = 0;
    ll root = 0;
    do {
        for(ll i = 0; i < N - 1; i++) {
            long double length;
            ll after = jun.at(i + 1);
            ll before = jun.at(i);
            length = pow(points.at(after).at(0) - points.at(before).at(0), 2) + pow(points.at(after).at(1) - points.at(before).at(1), 2);
            sum += sqrt(length);
        }
        root++;
    } while (next_permutation(jun.begin(), jun.end()));

    cout << fixed << setprecision(20) << sum / root << endl;
}