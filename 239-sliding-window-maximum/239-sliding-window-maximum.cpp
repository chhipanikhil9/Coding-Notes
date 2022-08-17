class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // T: O(N)
        vector<int> ans;
        int i=0,j=0;
        int n = nums.size();
        deque<int> dq;// insert and deletion O(1);
        while(i<n){
            while(!dq.empty() and nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(j>dq.front()){
                dq.pop_front();
            }
            if(i+1>=k){
                ans.push_back(nums[dq.front()]);
                j++;
            }
            i++;
        }
        return ans;
    }
};