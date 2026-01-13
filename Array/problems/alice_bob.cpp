#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool all_ones = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) all_ones = false;
    }

    
    if (all_ones) {
        cout << "Alice" << endl;
        return;
    }

    
    if (a[0] == 1 || a[n - 1] == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}