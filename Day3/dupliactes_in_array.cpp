class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        //XOR ing all array
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        for(int i=1;i<nums.size();i++){
            ans=ans^i;
        }
        return ans;
        }
};