
int recur(int i,int target,vector<int> &num,vector<vector<int>> &dp){
    if(target == 0){
        return 1;
    }
    if(i==0){
        return (target==num[0]);
    }
    
    if(dp[i][target]!=-1) 
        return dp[i][target];
    
    int take = (num[i]<=target)?recur(i-1,target-num[i],num,dp):0;
    int dontTake = recur(i-1,target,num,dp);
    return dp[i][target] = (take + dontTake);
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n+1,vector<int>(tar+1,-1));
    return recur(n-1,tar,num,dp);
}
