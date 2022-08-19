#include<bits/stdc++.h>

int recur(int cur,int pre,vector<vector<int>> &points,vector<vector<int>> &dp){
    // Base case
    if(cur==0){
        int maxi = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=pre){
                maxi = max(maxi,points[cur][i]);
            }
        }
        return maxi;
    }
        // if calculated before
        if(dp[cur][pre]!=-1){
            return dp[cur][pre];
        }
        
        // this will take maxi of points[cur][!pre]
        int maxi = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=pre){
                int point = points[cur][i]+recur(cur-1,i,points,dp);
                maxi = max(maxi,point);
            }
        }
        return dp[cur][pre] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
    // passing pre = 3 so it can calculate max of all three activities
    return recur(n-1,3,points,dp);
}
