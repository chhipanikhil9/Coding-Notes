class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int pre = 0;
        int cur = 1;
        int n = nums.size();
        while(cur<n){
            if(nums[cur]==nums[pre]) cur++;
            else{
                nums[++pre] = nums[cur++];
            }
        }
        return pre+1;
    }
};