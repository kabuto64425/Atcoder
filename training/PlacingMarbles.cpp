#include <bits/stdc++.h>
using namespace std;

int main() {
    string src;
    cin >> src;
    cout << count(src.cbegin(), src.cend(), '1') << endl;
}