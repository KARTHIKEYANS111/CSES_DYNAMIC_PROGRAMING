#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, x;
int arr[101];
const int mod = 1e9 + 7;
vector<int> dp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;

    dp.resize(x + 1);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(i - arr[j] >= 0) {
                dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
            }
        }
    }
    cout << dp[x] << endl;

    return 0;
}
