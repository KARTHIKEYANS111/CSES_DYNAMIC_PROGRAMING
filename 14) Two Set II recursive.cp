#include <bits/stdc++.h>
using namespace std;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int tot = n * (n + 1) / 2;

    if(tot % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(tot / 2 + 1, -1));


    function<int(int , int)> recur = [&](int idx, int s) {
        if(idx > n) {
            return 0;
        }
        if(s == tot / 2) {
            return 1;
        }
        if(s > tot / 2) return 0;

        if(dp[idx][s] != -1) return dp[idx][s];

        int pick = recur(idx + 1, s + idx);
        int notpick = recur(idx + 1, s);

        return dp[idx][s] = (pick + notpick) % mod;
    };

    cout << recur(1, 0) << endl;

    return 0;
}
