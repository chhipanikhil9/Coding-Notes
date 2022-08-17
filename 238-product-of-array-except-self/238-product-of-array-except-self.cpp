class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute force time: O(N^2)
        //              space : O(0);
        // int n = nums.size();
        // vector<int> ans(n,1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i!=j){
        //             ans[i] *= nums[j];
        //         }
        //     }
        // }
        // return ans;
        
        // T:O(N) S:O(1)
        int n = nums.size();
        vector<int> ans(n);
        
        int pre = 1;
        for(int i=0;i<n;i++){
            ans[i] = pre;
            pre *= nums[i];
        }
        
        int suf = 1;
        for(int i= n-1;i>=0;i--){
            ans[i] *= suf;
            suf *= nums[i];
        }
        return ans;
    }
};