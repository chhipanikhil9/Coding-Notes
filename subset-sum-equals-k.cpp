
int recur(int i,int k,vector<int> &arr,vector<vector<int>> &dp){
    
    if(k==0) 
        return true;
    if(i<0){
        return false;
    }
    if(dp[i][k]!=-1) 
        return dp[i][k];

    int take = (arr[i]<=k)?recur(i-1,k-arr[i],arr,dp):false;
    int dontTake = recur(i-1,k,arr,dp);
    return dp[i][k] = (take or dontTake);
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return recur(n-1,k,arr,dp);
}
