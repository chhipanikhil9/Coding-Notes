
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        for(int i=1;i<=amount;i++){
            dp[i] = amount+1;
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    int subprob = dp[i-coins[j]];
                    dp[i] = min(dp[i],1+subprob);
                }
            }
        }
        return (dp[amount]>amount)?-1:dp[amount];
    }
};