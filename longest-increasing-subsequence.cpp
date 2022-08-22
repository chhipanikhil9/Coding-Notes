#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9+7
using namespace std;




int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n = 6;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int dp[n + 1] = {0};
	dp[0] = 1;
	int ans = INT_MIN;
	for (int i = 1; i < n; i++) {
		dp[i] = INT_MIN;
		for (int j = 0; j < i; j++) {
			if (arr[j] <= arr[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
			else {
				dp[i] = 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
