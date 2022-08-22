class Solution {
public:
    
    int recur(int i,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(i<0){
            return false;
        }
        if(dp[i][target]!=-1)
            return dp[i][target];
        
        int take = (nums[i]<=target)?recur(i-1,target-nums[i],nums,dp):false;
        int dontTake = recur(i-1,target,nums,dp);
        
        return dp[i][target] = (take or dontTake);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        if(sum%2) return false;
        int target = sum/2;
        return recur(n-1,target,nums,dp);
    }
};