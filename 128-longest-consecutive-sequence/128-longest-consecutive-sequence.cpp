class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = nums.size();
        
        int maxSize = 0;
        
        for(int i=0;i<n;i++){
            // if nums[i] is starting then nums[i]-1 should not present in the set
            if(st.find(nums[i]-1) == st.end()){
                int len = 1;
                while(st.find(nums[i]+len) != st.end()){
                    len++;
                }
                maxSize = max(maxSize,len);
            }
        }
        return maxSize;
    }
};