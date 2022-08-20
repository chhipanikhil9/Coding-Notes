#include <bits/stdc++.h>


// Top-Down
int recur(int i,int j,int n,int m,vector<vector<int>> &mat,vector<vector<int>> &dp){
    // in bound
    if(j<0 or j>m){
        return -1e9;
    }
    //base case in 1st row max is mat[i][j];
    if(i==0){
        return mat[0][j];
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // recursive case
    int down = recur(i-1,j,n,m,mat,dp);
    int leftDig = recur(i-1,j-1,n,m,mat,dp);
    int rightDig = recur(i-1,j+1,n,m,mat,dp);
    return dp[i][j] = mat[i][j] + max({down,leftDig,rightDig});
}

int getMaxPathSum(vector<vector<int>> &mat)
{
    //  Write your code here.
    int n = mat.size();
    int m = mat[0].size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     int ans = INT_MIN;
//     for(int i=0;i<m;i++){
//         ans = max(ans,recur(n-1,i,n-1,m-1,mat,dp));
// //         cout<<ans<<endl;
//     }
//     return ans;
    
    // Bottom-Up=>
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<m;i++){
        dp[0][i] = mat[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = dp[i-1][j];
            int leftDig = ((j==0)?(-1e9):dp[i-1][j-1]);
            int rightDig = ((j==m-1)?-1e9:dp[i-1][j+1]);
            dp[i][j] = mat[i][j] + max(up,max(leftDig,rightDig));
//             cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = INT_MIN;
    for(int i=0;i<m;i++){
        ans = max(ans,dp[n-1][i]);
    }
    return ans;
}
