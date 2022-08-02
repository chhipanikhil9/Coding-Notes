#define ll long long
class Solution {
public:
    
    ll dp[105][105] = {0};
    ll count(int n,int m){
        if(n<0 or m<0){
            return 0;
        }
        if(n==0 and m==0){
            return 1;
        }
        if(dp[n][m]){
            return dp[n][m];
        }
        return dp[n][m] = (count(n-1,m) + count(n,m-1));
    }
    int uniquePaths(int m, int n) {
        return count(n-1,m-1);
    }
};