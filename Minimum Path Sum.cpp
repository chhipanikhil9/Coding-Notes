// Microsoft
#include<bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size();
    int n= grid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
     
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 and j==0){
                dp[0][0] = grid[0][0];
            }
            else{
                int up = INT_MAX,left =INT_MAX;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(up,left);
            }
        }
    }
    return dp[m-1][n-1];
}
