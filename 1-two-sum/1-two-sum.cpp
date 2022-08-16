class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int req = target-nums[i];
            if(mp.find(req)!=mp.end()){
                ans = {i,mp[req]};
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};