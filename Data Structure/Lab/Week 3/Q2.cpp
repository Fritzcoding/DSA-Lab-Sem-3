#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
#define ll long long

ll calculatedp(vector<ll> arr){
    ll n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0], arr[1]);
    // vector<ll> dp(n);
    // dp[0] = arr[0];
    // dp[1] = max(arr[0], arr[1]);
    // ll i = 2;
    // while(i < n){
    //     dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
    //     i++;
    // }
    // return dp[n-1];
    ll ans = numeric_limits<long long>::min();
    //cout << ans;
    ll maxprefix = arr[0];
    for(ll i = 2; i<n;i++){
        if(arr[i-2] > maxprefix)maxprefix = arr[i-2];
        ll temp = arr[i] + maxprefix;
        if(temp > ans) ans = temp;
    }
    return ans;
}

int main(){
    ll n, x;
  	vector<ll> arr;
  	cin >> n;
  	while(n--){
    	cin >> x;
      	arr.push_back(x);
    }
    cout << calculatedp(arr);
}