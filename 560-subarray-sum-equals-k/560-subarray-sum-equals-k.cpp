class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0,sum = 0;
        unordered_map<int,int> mp;
        mp[sum] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            // cout<<mp[sum-k]<<" ";
            if(mp.find(sum-k) != mp.end()){
                cnt += mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;   
    }
};