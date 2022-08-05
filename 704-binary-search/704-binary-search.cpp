class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        int ind = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                ind = mid;
                break;
            }
            else if(nums[mid]<target){
                l = l+1;
            }
            else{
                r = r-1;
            }
        }
        return ind;
    }
};