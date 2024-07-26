#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    vector<int> arr(n), dp(x + 1, 1e9);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - arr[j] >= 0) {
                dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
            }
        }
    }

    if(dp[x] == 1e9) {
        cout << -1 << endl;
    } else{
        cout << dp[x] << endl;
    }
    return 0;
}
