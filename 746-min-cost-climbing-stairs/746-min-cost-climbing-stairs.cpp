class Solution {
public:
    int dp[1005] = {0};
    int solve(vector<int>& cost, int i){
        int n = cost.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]) return dp[i];
        return dp[i] = (cost[i]+min(solve(cost,i+1),solve(cost,i+2)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost,0),solve(cost,1));
    }
};