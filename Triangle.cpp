#include<bits/stdc++.h>
// Top-Down => memoization
int recur(int i,int j,vector<vector<int>>& tri,vector<vector<int>>& dp){
    int n = tri.size();
    if(i==n-1 and j<=i){
        return tri[i][j];
    }
    if(i>=n or j>i){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down = recur(i+1,j,tri,dp);
    int rightDown = recur(i+1,j+1,tri,dp);
    return dp[i][j] = tri[i][j] + min(down,rightDown);
}


int minimumPathSum(vector<vector<int>>& tri, int n){
 /*   // for top-down
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return recur(0,0,tri,dp);
   */
    
    // Bottom-Up(Tabulation)=>
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e6+5));
    dp[0][0] = tri[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            int up = INT_MAX;
            int upLeft = INT_MAX;
            if(i>0 and j!=i) up = dp[i-1][j];
            if(i>0 and j>0) upLeft = dp[i-1][j-1];
            dp[i][j] = (tri[i][j] + min(up,upLeft));
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[n-1][i]);
//         cout<<ans<<" ";
    }
    return ans;
}
