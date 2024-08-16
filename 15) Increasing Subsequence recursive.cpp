#include<bits/stdc++.h>

using namespace std;

#define int long long


signed main() {

    int n; cin >> n;
    vector<int>arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> lis;

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if(lis.size() and it != lis.end()) {
            lis[it - lis.begin()] = arr[i];
        } else {
            lis.push_back(arr[i]);
        }
    }

    cout << lis.size() << endl;
}
