#include <bits/stdc++.h>
using namespace std;

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t; cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));


    function<int(int, int)> recur = [&](int i, int j) {

        if(i < 0) {
            return j + 1;
        }

        if(j < 0) {
            return i + 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = recur(i - 1, j - 1);
        }
        return dp[i][j] = 1 + min({recur(i - 1, j), recur(i - 1, j - 1), recur(i, j - 1)});

    };

    cout << recur(n - 1, m - 1) << endl;

    return 0;
}
