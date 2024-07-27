#include <bits/stdc++.h>
using namespace std;
 
// #define int long long
#define endl "\n"
 
int n, x;
int arr[101];
const int mod = 1e9 + 7;
 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> x;
 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    
    vector<int> nextState(x + 1, 0);
    nextState[0] = 1;

    for(int i = n - 1; i >= 0; i--) {
        vector<int> curState(x + 1, 0);
        curState[0] = 1;
        for(int j = 1; j <= x; j++) {
            int pick = 0;
            if(arr[i] <= j) pick = curState[j - arr[i]];
            int notpick = nextState[j];
            curState[j] = (pick + notpick) % mod;
        }
        nextState = curState;
    }
 
    cout << nextState[x] << endl;
 
 
    return 0;
}
