class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int moreneed=target-num;
            if(mpp.find(moreneed) != mpp.end()){
                return {mpp(moreneed),i}
            }
            mpp[num]=i;
        }
        return {-1,-1};

    }
};