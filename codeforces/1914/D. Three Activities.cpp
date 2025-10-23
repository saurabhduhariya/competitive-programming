#include <bits/stdc++.h>
using namespace std;

vector<int> get_best3(const vector<int>& a) {
    int n = a.size();
    vector<int> idx(3, -1);

    for (int i = 0; i < n; i++) {
        if (idx[0] == -1 || a[i] > a[idx[0]]) {
            idx[2] = idx[1];
            idx[1] = idx[0];
            idx[0] = i;
        } else if (idx[1] == -1 || a[i] > a[idx[1]]) {
            idx[2] = idx[1];
            idx[1] = i;
        } else if (idx[2] == -1 || a[i] > a[idx[2]]) {
            idx[2] = i;
        }
    }

    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<int> A = get_best3(a);
        vector<int> B = get_best3(b);
        vector<int> C = get_best3(c);

        long long ans = 0;
        for (int x : A) {
            for (int y : B) {
                for (int z : C) {
                    if (x != y && x != z && y != z) {
                        ans = max(ans, (long long)a[x] + b[y] + c[z]);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
