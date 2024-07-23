class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> P(n, 1);
        long long int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            P[i] = leftProduct;
            leftProduct *= nums[i];
        }
        long long int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            P[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        
        return P;        
    }
};