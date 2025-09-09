#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

vector<long long> p3(40); 

void precompute() {
    p3[0] = 1;
    for (int i = 1; i < 40; i++) {
        p3[i] = p3[i - 1] * 3;
    }
}

int idx(long long n) {
    for (int i = 1; i < 40; i++) {
        if (p3[i] > n) return i - 1;
    }
    return 39;
}

void solve() {
    long long n;
    cin >> n;
    long long a = n % 3;
    long long ans = 0;
    while (n >= 3) {
        int i = idx(n) + 1;
        ans += p3[i] + (i - 1) * p3[i - 2];
        n -= p3[i - 1];
    }
    ans += 3 * a;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
